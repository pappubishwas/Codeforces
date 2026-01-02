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
const int MOD = 1e9 + 7;
int rndRange(int l, int r) { return RNG() % (r - l + 1) + l; }
int powerl(int a, int b)
{
    int res = 1;
    while (b)
    {
        if (b & 1)
            res = res * a % MOD;
        a = a * a % MOD;
        b >>= 1;
    }
    return res;
}
int inMod(int a)
{
    return powerl(a, MOD - 2);
}

void Solve()
{
    int n;
    cin>> n;
    vector<int> pap(n+1),ans(n+1);
    for(int i=1;i<=n;i++){
        cin>>pap[i];
    }
    stack<pair<int,int>> st;
    for(int i=1;i<=n;i++){
        int c=0;
        while(pap[i]%2==0){
            pap[i]/=2LL;
            c++;     
        }
        ans[i]=ans[i-1];
        while(!st.empty()){
            if(c>32 || st.top().first <= (pap[i]*(1LL<<c))){
                int base=st.top().first,ex=st.top().second;
                ans[i]=(ans[i]-base*powerl(2LL,ex)%MOD+MOD)%MOD;
                ans[i]=(ans[i]+base)%MOD;
                c+=ex;
                st.pop();
            }else{
                break;
            }
        }
        st.push({pap[i],c});
        ans[i]=(ans[i]+pap[i]*powerl(2,c)%MOD)%MOD;
    }
    for(int i=1;i<=n;i++)cout<<ans[i]<<" ";
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