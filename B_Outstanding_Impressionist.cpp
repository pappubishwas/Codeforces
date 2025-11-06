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

void solve()
{
    int n, m, l, r, k;
    cin >> n;
    vector<pair<int, int>> pr;
    vector<int> prefix(2 * n + 1),count(2*n+1);
    for (int i = 0; i < n; i++)
    {
        cin >> l >> r;
        pr.push_back({l,r});
        if(l==r){
            prefix[l]=1; // single value point
            count[l]++;
        }
    }
    for(int i=1;i<=2*n;i++){
        prefix[i]+=prefix[i-1];
    }

    for(auto& [l,r]:pr){
        if(l==r && count[l]==1){
            cout<<1;
        }
        else if(prefix[r]-prefix[l-1]<(r-l+1)){
            cout<<1;
        }else{
            cout<<0;
        }
    }
    cout<<endl;

    // map<int, multiset<int>> mp;
    // for (int i = 0; i < n; i++)
    // {
    //     cin >> l >> r;
    //     pr.push_back({l, r});
    //     mp[l].insert(r);
    // }
    // for (auto &[l, r] : pr)
    // {
    //     int left = l, right = r;
    //     int res = 0;
    //     while (left <= right)
    //     {
    //         int mid = (left + right) / 2;
    //         if (mp.find(mid) == mp.end())
    //         {
    //             res = 1;
    //             break;
    //         }
    //         auto &v = mp[mid];
    //         if (mid == l)
    //         {
    //             v.erase(r);
    //             auto it = v.upper_bound(mid);
    //             if (it != v.end())
    //             {
    //                 res = 1;
    //                 v.insert(r);
    //                 break;
    //             }
    //             v.insert(r);
    //         }
    //         else
    //         {
    //             auto it = v.upper_bound(mid);
    //             if (it != v.end())
    //             {
    //                 res = 1;
    //                 break;
    //             }
    //         }
    //     }
    //     cout<<res;
    // }
    // cout << endl;
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
        solve();
    }

    auto end = chrono::high_resolution_clock::now();
    auto elapsed = chrono::duration_cast<chrono::nanoseconds>(end - begin);
    // cerr << "Time measured: " << elapsed.count() * 1e-9 << " seconds.\n";
    return 0;
}
