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
    int n, m,x,len;
    cin>>n>>m>>len;
    vector<pair<int,int>> hurdels(n),powerup(m);
    multiset<int> s;
    for(int i=0;i<n;i++){
        cin>> hurdels[i].first>>hurdels[i].second;
    }
    for(int i=0;i<m;i++){
        cin>> powerup[i].first>>powerup[i].second;
    }
    int pw=1;
    int j=0;
    int res=0;
    for(auto it:hurdels){
        int l=it.first,r=it.second;
        if(pw>(r-l+1)) continue;
        while(powerup[j].first<l && j<m){
            s.insert(powerup[j].second);
            j++;
        }
        while(!s.empty() && pw<=(r-l+1)){
            pw+=(*s.rbegin());
            auto t=prev(s.end());
            s.erase(t);
            res++;
        }
        if(pw<=(r-l+1)){
            cout<<-1<<endl;
            return;
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
    // t=1;
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