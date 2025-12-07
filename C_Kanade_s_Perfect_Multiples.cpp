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

// int rndRange(int l, int r) { return RNG() % (r - l + 1) + l; }

// int binaryLength(int n)
// {
//     return 64 - __builtin_clzll(n);
// }
// int mod = 998244353;
// const int N = 1e5 + 69;
// bool sv[N];

// void Solve()
// {
//     int n;
//     int k;
//     cin >> n >> k;

//     vector<int> arr(n);
//     for (int i = 0; i < n; ++i)
//         cin >> arr[i];

//     sort(arr.begin(), arr.end());
//     arr.erase(unique(arr.begin(), arr.end()), arr.end());

//     int m = arr.size();
//     vector<int> pap;

//     for (int x : arr)
//     {
//         if (k / x > n)
//             continue;
//         bool ok = true;
//         for (int ml = x; ml <= k; ml += x)
//         {
//             if (!binary_search(arr.begin(), arr.end(), ml))
//             {
//                 ok = false;
//                 break;
//             }
//         }
//         if (ok)
//             pap.push_back(x);
//     }

//     if (pap.empty())
//     {
//         cout << -1 << "\n";
//         return;
//     }

//     vector<bool> keep(pap.size(), true);

//     for (int i = 0; i < pap.size(); ++i)
//     {
//         if (!keep[i])
//             continue;
//         int x = pap[i];

//         for (int mult = 2 * x; mult <= k; mult += x)
//         {
//             auto it = lower_bound(pap.begin(), pap.end(), mult);
//             if (it != pap.end() && *it == mult)
//             {
//                 int idx = it - pap.begin();
//                 keep[idx] = false;
//             }
//         }
//     }

//     vector<int> mn;
//     for (int i = 0; i < pap.size(); ++i)
//     {
//         if (keep[i])
//             mn.push_back(pap[i]);
//     }

//     vector<bool> cv(m, false);
//     int cnt = 0;

//     for (int base : mn)
//     {
//         for (int mult = base; mult <= k; mult += base)
//         {
//             auto it = lower_bound(arr.begin(), arr.end(), mult);
//             if (it != arr.end() && *it == mult)
//             {
//                 int idx = it - arr.begin();
//                 if (!cv[idx])
//                 {
//                     cv[idx] = true;
//                     cnt++;
//                 }
//             }
//         }
//     }

//     if (cnt == m)
//     {
//         cout << mn.size() << "\n";
//         for (int i = 0; i < mn.size(); ++i)
//         {
//             cout << mn[i] << (i + 1 == mn.size() ? "" : " ");
//         }
//         cout << "\n";
//     }
//     else
//     {
//         cout << -1 << "\n";
//     }
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

int rndRange(int l, int r) { return RNG() % (r - l + 1) + l; }

int binaryLength(int n)
{
    return 64 - __builtin_clzll(n);
}
int mod = 998244353;
const int N = 1e5 + 69;
bool sv[N];

void Solve()
{
    int n, r, d, m,k;
    cin >> n >>k;
    set<int> s,t;
    for(int i=0;i<n;i++){
        cin>>d;
        s.insert(d);
        t.insert(d);
    }
    vector<int> ans;
    while(s.size()){
        int x=*s.begin();
        ans.push_back(x);
        for(int i=x;i<=k;i+=x){
            if(t.count(i)){
                s.erase(i);
            }else{
                cout<<-1<<endl;
                return;
            }
        }
    }
    cout<<ans.size()<<endl;
    for(auto x:ans) cout<<x<<" ";
    cout<<endl;

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