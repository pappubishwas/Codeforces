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
int primes[] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53};

void solve()
{
    int n, m;
    cin >> n >> m;
    vector<vector<int>> pap(n, vector<int>(m));
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            cin >> pap[i][j];
        }
    }
    map<int, int> mp;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            int count = 1;
            if (i-1>=0 && pap[i-1][j]==pap[i][j]) count++;
            if (i+1<n && pap[i+1][j]==pap[i][j]) count++;
            if (j-1>=0 && pap[i][j-1]==pap[i][j]) count++;
            if (j+1<m && pap[i][j+1]==pap[i][j]) count++;
            if(count>=2)
                mp[pap[i][j]]=max(mp[pap[i][j]],2LL);
            else mp[pap[i][j]]=max(mp[pap[i][j]],1LL);    
        }
    }
    int ans = 0;
    int mx=LLONG_MIN;
    for(auto it:mp){
        mx=max(mx,it.second);
        ans+=it.second;
    }
    cout<<ans-mx<<"\n";
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