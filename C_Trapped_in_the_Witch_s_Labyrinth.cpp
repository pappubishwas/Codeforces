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
vector<vector<int>> dir={{0,1},{1,0},{-1,0},{0,-1}}; // R D U L

void solve()
{
    int n,m;
    cin>>n>>m;
    vector<string> grid(n);
    for(int i=0;i<n;i++){
        cin>>grid[i];
    }
    vector<vector<bool>> visited(n,vector<bool>(m,false));
    queue<pair<int,int>> q;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(i==0 && grid[i][j]=='U'){
                q.push({i,j});
                visited[i][j]=true;
            }
            if(i==n-1 && grid[i][j]=='D'){
                q.push({i,j});
                visited[i][j]=true;
            }
            if(j==0 && grid[i][j]=='L'){
                q.push({i,j});
                visited[i][j]=true;
            }
            if(j==m-1 && grid[i][j]=='R'){
                q.push({i,j});
                visited[i][j]=true;
            }
        }
    }
    while(!q.empty()){
        int r=q.front().first;
        int c=q.front().second;
        q.pop();

        for(int i=0;i<4;i++){
            int nr=r+dir[i][0];
            int nc=c+dir[i][1];
            if(nr>=0 && nc>=0 && nr<n && nc<m && !visited[nr][nc]){
                bool flag=false;
                if(i==0 && grid[nr][nc]=='L') flag=true;
                if(i==1 && grid[nr][nc]=='U') flag=true;
                if(i==2 && grid[nr][nc]=='D') flag=true;
                if(i==3 && grid[nr][nc]=='R') flag=true;

                if(flag){
                    visited[nr][nc]=true;
                    q.push({nr,nc});
                }
            }
        }
    }

    int ans=0;

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(grid[i][j]=='?'){
                bool flag=false;
                for(auto& d:dir){
                    int nr=i+d[0];
                    int nc=j+d[1];
                    if(nr>=0 && nc>=0 && nr<n && nc<m && !visited[nr][nc]){
                        flag=true;
                    }
                }
                if(flag) ans++;
            }else{
                if(!visited[i][j]) ans++;
            }
        }
    }
    cout<<ans<<endl;
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