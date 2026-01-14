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
map<int,int>mp;
int solve(int n,int k){
    if(n<k) return INF;
    if(n==k) return 0;
    if(mp.find(n)!=mp.end()) return mp[n];
    int l=n/2LL;
    int r=(n+1)/2LL;
    int res=INF;
    if(l==r){
        res=solve(l,k);
    }else{
        res=min(res,solve(l,k));
        res=min(res,solve(r,k));
    }
    if(res==INF) return INF;
    return mp[n]=res+1;
}
void Solve()
{
    int n,k;
    cin>>n>>k;
    if(n==k){
        cout<<0<<endl;
        return;
    }else if(n<k){
        cout<<-1<<endl;
        return;
    }
    int level=1;
    set<int> q;
    q.insert(n);
    while(!q.empty()){
        set<int> t;
        for(int v:q){
            int l=v/2LL;
            int r=(v+1)/2LL;
            if(l==k || r==k){
                cout<<level<<endl;
                return;
            }
            if(l>k) t.insert(l);
            if(r>k) t.insert(r);
        }
        q=t;
        level++;
    }
    cout<<-1<<endl;
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