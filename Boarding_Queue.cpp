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

vector<vector<int>> dir={{0,1},{1,0},{-1,0},{0,-1}};

void solve()
{
    int r,c,t,p;
    cin>>r>>c>>t>>p;
    vector<vector<int>> grid(r,vector<int>(c));
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            cin>>grid[i][j];
        }
    }
    set<int> s;
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            if(grid[i][j]==0) continue;
            int diff=p-grid[i][j];
            if(diff<0) continue;
            for(auto d:dir){
                int ni=i+d[0];
                int nj=j+d[1];
                if(min(ni,nj)>=0 && ni<r && nj<c && grid[ni][nj]!=0){
                    if(diff+grid[ni][nj]<=t){
                        s.insert(diff+grid[ni][nj]);
                    }
                }
            }
        }
    }
    cout<<s.size()<<"/"<<t-1<<endl;
}




int32_t main()
{
    auto begin = chrono::high_resolution_clock::now();
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t = 1;
    // freopen("in",  "r", stdin);
    // freopen("out", "w", stdout);

    // cin >> t;
    // for (int i = 1; i <= t; i++)
    // {
        // cout << "Case #" << i << ": ";
        solve();
    // }

    auto end = chrono::high_resolution_clock::now();
    auto elapsed = chrono::duration_cast<chrono::nanoseconds>(end - begin);
    // cerr << "Time measured: " << elapsed.count() * 1e-9 << " seconds.\n";
    return 0;
}



