// #include <bits/stdc++.h>
// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp>
// using namespace std;
// using namespace __gnu_pbds;
// #define int long long
// #define INF (int)1e18

// mt19937_64 RNG(chrono::steady_clock::now().time_since_epoch().count());


// template<class T>
// using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;




// bool check(vector<int> &p, int n, int mex, int k) {
//     ordered_set<int> st;
//     for (int i = 0; i < n; i++) {
//         st.insert(p[i]);
//         auto it = st.lower_bound(mex-1); 
//         if(it==st.end() ) it--;
//         int count=st.order_of_key(*it);
//         //cout<<*it<<" "<<count<<endl;
//         if (*it==mex-1 && count==mex-1) { 
//             k--;
//             st = ordered_set<int>();
//         }
//     }
//     //cout<<endl;
//     return k <= 0;
// }



// void Solve() {
//     int n, k;
//     cin >> n >> k;
//     vector<int> pap(n);
//     for (auto &p : pap)
//         cin >> p;

//     int res = 0;
//     int l = 1, r = n + 2;
//     // check(pap,n,3,k);
//     // return;
//     while (l <= r) {
//         int mid = (l + r) / 2;
//         if (check(pap, n, mid, k)) {
//             res = max(mid, res);
//             l = mid + 1;
//         } else {
//             r = mid - 1;
//         }
//     }

//     cout << res << endl;
// }

// int32_t main() {
//     auto begin = chrono::high_resolution_clock::now();
//     ios_base::sync_with_stdio(0);
//     cin.tie(0);

//     int t = 1;
//     // freopen("in",  "r", stdin);
//     // freopen("out", "w", stdout);

//     cin >> t;
//     for (int i = 1; i <= t; i++) {
//         // cout << "Case #" << i << ": ";
//         Solve();
//     }

//     auto end = chrono::high_resolution_clock::now();
//     auto elapsed = chrono::duration_cast<chrono::nanoseconds>(end - begin);
//     // cerr << "Time measured: " << elapsed.count() * 1e-9 << " seconds.\n";
//     return 0;
// }



#include <bits/stdc++.h>
using namespace std;
#define int long long

bool check(vector<int> &p, int n, int mex, int k) {
    vector<int> freq(mex + 1, 0);
    int count = 0;
    for (int i = 0; i < n; i++) {
        if (p[i] < mex) {
            if (freq[p[i]] == 0) count++;
            freq[p[i]]++;
        }
        if (count == mex) {
            k--;
            fill(freq.begin(), freq.end(), 0);
            count = 0;
        }
    }
    return k <= 0;
}

void Solve() {
    int n, k;
    cin >> n >> k;
    vector<int> pap(n);
    for (auto &p : pap)
        cin >> p;

    int res = 0;
    int l = 1, r = n + 2;
    while (l <= r) {
        int mid = (l + r) / 2;
        if (check(pap, n, mid, k)) {
            res = max(mid, res);
            l = mid + 1;
        } else {
            r = mid - 1;
        }
    }
    cout << res << "\n";
}

int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t = 1;
    cin >> t;
    while (t--) Solve();
    return 0;
}
