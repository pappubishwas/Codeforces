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
    int n,m;
    cin>>n>>m;
    vector<int> pap(m),a(n+1);
    for(int i=0;i<m;i++){
        cin>> pap[i];
    }
    sort(pap.begin(),pap.end(),greater<int>());
    for(int i=1;i<=n;i++){
        for(int j=i+i;j<=n;j+=i){
            if(a[i]==a[j]) a[j]++;
        }
    }
    if(*max_element(a.begin(),a.end())>=m){
        cout<<-1<<endl;
        return;
    }
    for(int i=1;i<=n;i++){
        cout<<pap[a[i]]<<" ";
    }
    cout<<endl;
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