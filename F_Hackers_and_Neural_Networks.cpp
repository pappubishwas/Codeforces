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
const int mod = 998244353;
const int MOD = 1e9 + 7;
int rndRange(int l, int r) { return RNG() % (r - l + 1) + l; }
int fact[200001];
int powerl(int a, int b)
{
    int res = 1;
    while (b)
    {
        if (b & 1)
            res = res * a % mod;
        a = a * a % mod;
        b >>= 1;
    }
    return res;
}
int inMod(int a)
{
    return powerl(a, mod - 2);
}
void Solve()
{
    int n, x, y, m;
    cin >> n >> m;
    vector<string> pap(n);
    for(int i=0;i<n;i++){
        cin>>pap[i];
    }
    vector<vector<string>> g(m, vector<string>(n));
    for (int i = 0; i < m; i++){
        for(int j=0;j<n;j++){
            cin>>g[i][j];
        }
    }
    int mx=0;
    vector<int> isPossible(n,0); // it will check each position has the matching or not
    for(int i=0;i<m;i++){
        int cnt=0; // how many position matched with g
        for(int j=0;j<n;j++){ // for each row
            if(pap[j]==g[i][j]){ // matching
                isPossible[j]=1;
                cnt++;
            }
        }
        mx=max(mx,cnt); // maximum postions matched with g after n operations
    }
    for(int i=0;i<n;i++){
        if(isPossible[i]==0){ // there is a postions which is not matched with g
            cout<<-1<<endl;
            return;
        }
    }
    cout<<n+2LL*(n-mx)<<endl; // with n opertaions we can make mx number of positions matched with g, for rest n-mx position will be take 2nd op and for each op there is  need 2 operations remove and add by first oprations
}
int32_t main()
{
    auto begin = chrono::high_resolution_clock::now();
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t = 1;
    cin >> t;

    for (int i = 1; i <= t; i++)
    {
        Solve();
    }

    auto end = chrono::high_resolution_clock::now();
    auto elapsed = chrono::duration_cast<chrono::nanoseconds>(end - begin);
    return 0;
}