// #include <bits/stdc++.h>
// using namespace std;
// #define int long long
// #define INF (int)1e18

// mt19937_64 RNG(chrono::steady_clock::now().time_since_epoch().count());
// int MOD=1e9+7;

// struct Func{
//     int a, b, c;
// };

// // check if f1, f2 are indep
// // INDEP COND -> f2 - f1 = (a2 - a1) x^2 + (b2 - b1) x + (c2 - c1) = ax^2+b+c

// // 1. if (a2 == a1) -> f2 - f1 = (b2 - b1)x + (c2 - c1) -> Line 
// //                          f2 == f1  -> x = (c2 - c1) / (b2 - b1)
// //                          if (b2 == b1) then f1, f2 not equal -> indep
// // 1. -> if (a2 == a1) -> (b2 != b1) for indep

// // 2. else f1 != f2 -> eqn has no real roots
// // 2. -> D < 0 -> (b^2 < 4*a*c) for indep
// bool valid(Func &f1, Func &f2){
//     // f1 < f2
//     if (f1.a == f2.a) return f1.b == f2.b;      // 1.
//     int a = f2.a - f1.a, b = f2.b - f1.b, c = f2.c - f1.c;
//     return b*b < 4*a*c;             // 2.
// }

// void Solve() 
// {
//    int n; cin >> n;
//     vector<Func> f(n); for (auto& i : f) cin >> i.a >> i.b >> i.c;
//     vector<int> idx(n); 
//     for (int i = 0; i < n; i++) idx[i] = i;

//     // for indep f1, f2 -> (f1 < f2 for all x) or (f1 > f2 for all x)
//     // if a1 < a2 -> f1 < f2    [x^2 dominate for large x]
//     sort(idx.begin(), idx.end(), [&](int& i, int& j){
//         if (f[i].a != f[j].a) return f[i].a < f[j].a;
//         if (f[i].b != f[j].b) return f[i].b < f[j].b;
//         return f[i].c < f[j].c;
//     });

//     // bef[i] -> max count of f less than f[i] such that all f are indep
//     // bef[i] -> does not include f[i]
//     vector<int> bef(n);
//     for (int i = 0; i < n; i++){
//         for (int j = 0; j < i; j++){
//             // if f[i],f[j] indep and bef[j] + 1 > bef[i] -> bef[i] = bef[j]+1 
//             if (bef[j] >= bef[i] && valid(f[idx[j]], f[idx[i]])) bef[i] = bef[j] + 1;
//         }
//     }
    
//     // af[i] -> max count of f greater than f[i] such that all f are indep
//     // af[i] -> does not include f[i]
//     vector<int> af(n);
//     for (int i = n-1; i >= 0; i--){
//         for (int j = n-1; j > i; j--){
//             // if f[i],f[j] indep and af[j] + 1 > af[i] -> af[i] = af[j]+1 
//             if (af[j] >= af[i] && valid(f[idx[i]], f[idx[j]])) af[i] = af[j] + 1;
//         }
//     }

//     vector<int> ans(n);
//     // ans[i] = bef[i] + af[i] + 1      (bef, af doesnt include f[i])
//     for (int i = 0; i < n; i++) ans[idx[i]] = bef[i] + af[i] + 1;
//     for (int i : ans) cout << i << " "; cout << '\n';
// }

// int32_t main() 
// {
//     auto begin = std::chrono::high_resolution_clock::now();
//     ios_base::sync_with_stdio(0);
//     cin.tie(0);
//     int t = 1;
//     // freopen("in",  "r", stdin);
//     // freopen("out", "w", stdout);
    
//     cin >> t;
//     for(int i = 1; i <= t; i++) 
//     {
//         //cout << "Case #" << i << ": ";
//         Solve();
//     }
//     auto end = std::chrono::high_resolution_clock::now();
//     auto elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin);
//     //cerr << "Time measured: " << elapsed.count() * 1e-9 << " seconds.\n"; 
//     return 0;
// }





#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>

using namespace std;
using ll = long long;

struct Func {
    ll a, b, c;
    int original_idx; // Track the original index inside the struct
    
    // Member function to check independence with another Func
    bool is_independent_from(const Func& other) const {
        if (a == other.a) return b == other.b;
        
        ll delta_a = other.a - a;
        ll delta_b = other.b - b;
        ll delta_c = other.c - c;
        
        return (delta_b * delta_b) < (4LL * delta_a * delta_c);
    }
};

void solve() {
    int n; 
    cin >> n;
    
    vector<Func> f(n);
    for (int i = 0; i < n; i++) {
        cin >> f[i].a >> f[i].b >> f[i].c;
        f[i].original_idx = i;
    }

    // Sort functions based on a, then b, then c
    // This establishes the guaranteed non-intersecting vertical order
    sort(f.begin(), f.end(), [](const Func& f1, const Func& f2) {
        if (f1.a != f2.a) return f1.a < f2.a;
        if (f1.b != f2.b) return f1.b < f2.b;
        return f1.c < f2.c;
    });

    vector<int> bef(n, 0);
    vector<int> af(n, 0);

    // Calculate maximum independent chains BEFORE each element
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < i; j++) {
            // Note: The short-circuit 'bef[j] >= bef[i]' is a great optimization!
            if (bef[j] >= bef[i] && f[j].is_independent_from(f[i])) {
                bef[i] = bef[j] + 1;
            }
        }
    }
    
    // Calculate maximum independent chains AFTER each element
    for (int i = n - 1; i >= 0; i--) {
        for (int j = n - 1; j > i; j--) {
            if (af[j] >= af[i] && f[i].is_independent_from(f[j])) {
                af[i] = af[j] + 1;
            }
        }
    }

    // Combine answers and map them back to their original input indices
    vector<int> ans(n);
    for (int i = 0; i < n; i++) {
        ans[f[i].original_idx] = bef[i] + af[i] + 1;
    }
    
    for (int i = 0; i < n; i++) {
        cout << ans[i] << (i == n - 1 ? "" : " ");
    }
    cout << '\n';
}

int main() {
    // Fast I/O
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);

    int t; 
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}