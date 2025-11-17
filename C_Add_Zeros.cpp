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
int dfs(int par,int val,map<int,vector<int>>& mp,vector<int>& distance){
    int take=par-1+val;
    int res=par-1;
    distance[par]=0;
    for(auto& v:mp[take]){
        if(distance[v]==-1){
            res=max(res,par-1+dfs(v,take,mp,distance));
        }else{
            res=max(res,distance[v]+par-1);
        }
    }
    return distance[par]=res;
}

void solve()
{
    int n, k;
    cin >> n;
    vector<int> pap(n);
    for(auto& t:pap)cin>>t;
    vector<int> st;
    map<int,vector<int>> mp;
    for(int i=0;i<n;i++){
        if(n-i==pap[i]){
            st.push_back(i+1);
        }else{
            int need=n-i;
            if(pap[i]>need){
                mp[pap[i]-need].push_back(i+1);
            }
        }
    }
    vector<int> distance(n+1,-1);
    if(st.size()==0){
        cout<<n<<endl;
        return;
    }
    int res=0;
    for(int u:st){
        res=max(res,dfs(u,0,mp,distance));
    }
    cout<<res+n<<endl;
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