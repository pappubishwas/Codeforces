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
int rndRange(int l, int r) { return RNG() % (r - l + 1) + l; }

int powerl(int a,int b){
    int res=1;
    while(b){
        if(b&1) res=res*a%mod;
        a=a*a%mod;
        b>>=1;
    }
    return res;
}
int inMod(int a){
    return powerl(a,mod-2);
}
void Solve()
{
    int n,m,k;
    cin>>n>>m>>k;
    vector<int> a(m),q(k);
    for(auto& x:a)cin>>x;
    for(auto& x:q)cin>>x;
    string s(m,'0');
    if(n-k>=2){
        cout<<s<<endl;
    }else if(n==k){
        cout<<string(m,'1')<<endl;
    }else{
        set<int> st(q.begin(),q.end());
        for(int i=0;i<m;i++){
            if(st.find(a[i])==st.end()) s[i]='1';
        }
        cout<<s<<endl;
    }
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