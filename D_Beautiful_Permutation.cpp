// #include <bits/stdc++.h>
// using namespace std;

// #define int long long
// #define INF (int)1e18

// mt19937_64 RNG(chrono::steady_clock::now().time_since_epoch().count());

// int que() {
//     int ans;
//     cin >> ans;
//     return ans;
// }

// void Solve() {
//     int n;
//     cin >> n;

//     cout << 1 << " " << 1 << " " << n << endl;
//     cout.flush();
//     int osum_total = que();

//     cout << 2 << " " << 1 << " " << n << endl;
//     cout.flush();
//     int nsum_total = que();

//     int len_diff = nsum_total - osum_total; 
//     int search_l = 1, search_r = n;
//     int found_l = n; 

//     while (search_l <= search_r) {
//         int mid = search_l + (search_r - search_l) / 2;


//         cout << 1 << " " << 1 << " " << mid << endl;
//         cout.flush();
//         int osum_prefix = que();

//         cout << 2 << " " << 1 << " " << mid << endl;
//         cout.flush();
//         int nsum_prefix = que();

//         if (nsum_prefix > osum_prefix) {

//             found_l = mid;
//             search_r = mid - 1;
//         } else {
//             search_l = mid + 1;
//         }
//     }
//     int found_r = found_l + len_diff - 1;
//     cout << "! " << found_l << " " << found_r << endl;
//     cout.flush();
// }

// int32_t main() {
//     ios_base::sync_with_stdio(false);
//     cin.tie(nullptr);

//     auto begin = chrono::high_resolution_clock::now();

//     int t = 1;
//     // freopen("in", "r", stdin);
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
#define INF (int)1e18

mt19937_64 RNG(chrono::steady_clock::now().time_since_epoch().count());

int que() {
    int ans;
    cin >> ans;
    return ans;
}

void Solve() {
    int n, k, m, l, r;
    cin >> n;

    cout << 1 << " " << 1 << " " << n << endl;
    cout.flush();
    int osum = que();

    cout << 2 << " " << 1 << " " << n << endl;
    cout.flush();
    int nsum = que();

    int diff = nsum - osum;

    l = 1;
    r = n;
    int res = 1;

    while (l <= r) {
        int mid = (l + r) / 2;

        cout << 1 << " " << 1 << " " << mid << endl;
        cout.flush();
        int osum = que();

        cout << 2 << " " << 1 << " " << mid << endl;
        cout.flush();
        int nsum = que();

        if (osum == nsum) {
            res = mid+1;
            l = mid + 1;
        } else {
            r = mid - 1;
        }
    }

    cout << "! " << res << " " << res + diff - 1 << endl;
    cout.flush();
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    auto begin = chrono::high_resolution_clock::now();

    int t = 1;
    // freopen("in", "r", stdin);
    // freopen("out", "w", stdout);

    cin >> t;
    for (int i = 1; i <= t; i++) {
        // cout << "Case #" << i << ": ";
        Solve();
    }

    auto end = chrono::high_resolution_clock::now();
    auto elapsed = chrono::duration_cast<chrono::nanoseconds>(end - begin);
    // cerr << "Time measured: " << elapsed.count() * 1e-9 << " seconds.\n";

    return 0;
}