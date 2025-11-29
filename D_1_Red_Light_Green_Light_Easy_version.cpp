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
    int n,k;
    cin >> n>>k;
    vector<int> p(n),d(n);
    for(int i=0;i<n;i++){
        cin>> p[i];
    }
    for(int i=0;i<n;i++){
        cin>> d[i];
    }
    int q;
    cin>> q;
    vector<int> qpos(q);
    for(int i=0;i<q;i++){
        cin>> qpos[i];
    }
    int i=0;
    while (i<q)
    {
        if(p.back()<qpos[i]){ // if query position is greater than all positions
            cout<<"YES\n";
            i++;
            continue;
        }
        int currPos=qpos[i];
        int time=0;
        int currIndex=lower_bound(begin(p),end(p),qpos[i]) - p.begin(); // first position which is greater than or equal to query position
        int dir=1;
        bool isPos=true;
        vector<vector<bool>> visited(3,vector<bool>(n,false));
        for(int i=currIndex;i<n && i>=0;i+=dir){
                time+=abs(p[i]-currPos)%k;
                currPos=p[i];
                if(time%k==d[i]){
                    if(visited[dir+1][i]){ // if that position and direction is already visited then it is in loop
                        isPos=false;
                        break;
                    }
                    visited[dir+1][i]=true;
                    dir*=-1;
                }
        }
        
        if(isPos){
            cout<<"YES\n";
        }else{
            cout<<"NO\n";   
        }
        i++;
    }
    
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