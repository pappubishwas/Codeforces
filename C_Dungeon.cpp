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


void solve() {
    int n,m,t;
    cin >> n>>m;
    vector<int> papb(m),papc(m),zeroc;
    multiset<int> sword;
    multiset<pair<int,int>> nonmonster;
    for (int i = 0; i < n; ++i) {
        cin >> t;
        sword.insert(t);
    }

    for(int i=0;i<m;i++){
        cin>> papb[i];
    }

    for(int i=0;i<m;i++){
        cin>> papc[i];
        if(papc[i]==0){
            zeroc.push_back(papb[i]);
        }else{
            nonmonster.insert({papb[i],papc[i]});
        }
    }

    int res=0;
    for(auto& it:nonmonster){
        int y=it.first;
        auto itr=sword.lower_bound(y);
        if(itr==sword.end()) break;
        int x=*itr;
        res++;
        sword.erase(itr);
        sword.insert(max(x,it.second));
    }
    sort(zeroc.begin(),zeroc.end());
    for(int i=0;i<zeroc.size();i++){
        auto itr=sword.lower_bound(zeroc[i]);
        if(itr!=sword.end()){
            res++;
            sword.erase(itr);
        }
    }
    cout<<res<<endl;
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
