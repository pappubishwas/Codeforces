#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
#define int long long
#define INF (int)1e18
mt19937_64 RNG(chrono::steady_clock::now().time_since_epoch().count());
template <class T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

int binaryLength(int n)
{
    return 64 - __builtin_clzll(n);
}

void Solve()
{
    // int n,m,x;
    // cin>>n>>m;
    // int ans=0;
    // vector<int> pap(m);
    // for(auto &it:pap) cin>>it;

    // sort(pap.begin(),pap.end());
    // for(int i=0;i<m;i++){
    //     for(int j=i+1;j<m;j++){
    //         int diff=n-pap[j];
    //         int com=min(pap[i],pap[i]-diff+1LL);
    //         if(pap[i]==n) com=pap[i]-1;
    //         ans+=max(0LL,com);
    //     }
    // }
    // cout<<2*ans<<endl;
        int n, m;
        cin >> n >> m;
        vector<int> a(m);
        vector<int> cnt(n + 1); 
        for(int i = 0; i < m; i++) {
            cin >> a[i];
            cnt[a[i]]++;
        }
        for(int i = n - 1; i >= 0; i--) {
            cnt[i] += cnt[i + 1];
        }
        int wochien = 0;
        for(int i = 1; i < n; i++) {
            wochien += 1LL * cnt[i] * cnt[n - i];
            //cout<<cnt[i]<<" "<<cnt[n - i]<<"\n";
            wochien -= cnt[max(i, n - i)];
        }
        cout << wochien << "\n";

}

int32_t main()
{
    auto begin = chrono::high_resolution_clock::now();
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t = 1;
    // freopen("in",  "r", stdin);
    // freopen("out", "w", stdout);

    cin >> t;
    for (int i = 1; i <= t; i++)
    {
        // cout << "Case #" << i << ": ";
        Solve();
    }

    auto end = chrono::high_resolution_clock::now();
    auto elapsed = chrono::duration_cast<chrono::nanoseconds>(end - begin);
    // cerr << "Time measured: " << elapsed.count() * 1e-9 << " seconds.\n";
    return 0;
}








// #include <bits/stdc++.h>
// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp>
// using namespace std;
// using namespace __gnu_pbds;
// #define int long long
// #define INF (int)1e18
// mt19937_64 RNG(chrono::steady_clock::now().time_since_epoch().count());
// template <class T>
// using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

// int binaryLength(int n)
// {
//     if (n == 0) return 1; 
//     return 64 - __builtin_clzll(n);
// }

// void Solve()
// {
//     int n, m;
//     cin >> n >> m;
//     int ans = 0;
//     vector<int> pap(m);
//     for (auto &it : pap)
//         cin >> it;

//     sort(pap.begin(), pap.end());

//     vector<int> pref_val(m + 1, 0);
    
//     for (int i = 0; i < m; i++)
//     {
//         pref_val[i + 1] = pref_val[i] + pap[i];
        
//     }

//     for (int j = 1; j < m; j++)
//     {
//         int C_j = -n + pap[j] + 1;

//         if (C_j >= 0)
//         {
//             ans += pref_val[j];
//         }
//         else
//         {
//             // C_j < 0
//             // We need sum(max(0, pap[i] + C_j)) for i from 0 to j-1
//             // Find first i where pap[i] > -C_j
//             int k = upper_bound(pap.begin(), pap.begin() + j, -C_j) - pap.begin();

//             // For i from 0 to k-1, sum is 0
//             // For i from k to j-1, sum is (pap[i] + C_j)
            
//             int count = j - k;
//             if (count > 0)
//             {
//                 // Sum(pap[i]) for i from k to j-1
//                 int sum_pap_i = pref_val[j] - pref_val[k];
//                 ans += (sum_pap_i + (int)count * C_j);
//             }
//         }
//     }

//     // Apply correction for the special case: if(pap[i]==n)
//     // Find the contiguous range of 'n'
//     auto it1 = lower_bound(pap.begin(), pap.end(), n);
//     auto it2 = upper_bound(pap.begin(), pap.end(), n);
//     int start_n = it1 - pap.begin();
//     int end_n = it2 - pap.begin();

//     // Correction per pair = (special contribution) - (standard contribution)
//     // Special: max(0, n-1)
//     // Standard: max(0, n) (since pap[j] >= n)
//     int correction_per_pair = max(0LL, n - 1) - max(0LL, n);

//     if (correction_per_pair != 0)
//     {
//         for (int i = start_n; i < end_n; i++)
//         {
//             // i is an index where pap[i] == n
//             // j must be > i. The number of such j's is (m-1) - i.
//             int j_count = m - 1 - i;
//             ans += (int)j_count * correction_per_pair;
//         }
//     }

//     cout << 2 * ans << endl;
// }

// int32_t main()
// {
//     auto begin = chrono::high_resolution_clock::now();
//     ios_base::sync_with_stdio(0);
//     cin.tie(0);

//     int t = 1;
//     // freopen("in",  "r", stdin);
//     // freopen("out", "w", stdout);

//     cin >> t;
//     for (int i = 1; i <= t; i++)
//     {
//         // cout << "Case #" << i << ": ";
//         Solve();
//     }

//     auto end = chrono::high_resolution_clock::now();
//     auto elapsed = chrono::duration_cast<chrono::nanoseconds>(end - begin);
//     // cerr << "Time measured: " << elapsed.count() * 1e-9 << " seconds.\n";
//     return 0;
// }