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
int fact[51],infact[51];
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
void preCompute(){
    fact[0]=1;
    infact[0]=1;
    for(int i=1;i<=50;i++){
        fact[i]=(fact[i-1]*i)%mod;
        infact[i]=inMod(fact[i]);
    }
}
int nComr(int n,int r){
    if(r<0 || r>n) return 0;
    return (((fact[n]*infact[r])%mod)*infact[n-r])%mod;
}
int sol(int n, vector<int>& pap)
{
    int total=accumulate(pap.begin(),pap.end(),0LL);
    int times=total/n;
    int rem=total%n;

    int need=0;
    int count=0;
    for(int i=1;i<=n;i++){
        if(times>=pap[i]) {
            need+=(times-pap[i]);
        }
    }
    if(need>pap[0]) return 0;

    for(int i=1;i<=n;i++){
        if(pap[i]<=times) count++;
    }

    int mx=min({rem,count,pap[0]-need});
    int mn=max(0LL,rem-n+count);
    int res=0;
    for(int i=mn;i<=mx;i++){
        int temp=(nComr(count,i)*nComr(n-count,rem-i))%mod;
        res=(res+temp)%mod;
    }
    if(mx<mn) return 0;
    res= (((res*fact[rem])%mod)*fact[n-rem])%mod;
    return res;
}
void Solve()
{
    int n;
    cin >> n;

    vector<int> pap(n+1);
    for(int i=0;i<=n;i++)cin>> pap[i];
    int ans1 = sol(n,pap);
    cout << ans1<< endl;
}
int32_t main()
{
    auto begin = chrono::high_resolution_clock::now();
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t = 1;
    cin >> t;
    preCompute();
    for (int i = 1; i <= t; i++)
    {
        Solve();
    }

    auto end = chrono::high_resolution_clock::now();
    auto elapsed = chrono::duration_cast<chrono::nanoseconds>(end - begin);
    return 0;
}