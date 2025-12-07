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
int solve(int n,vector<vector<int>>& v,vector<int>& a){
    vector<bool> v1(n,false),v2(n,false),v3(n,false);
    for(int i=1;i<n;i++){
        for(int j=0;j<n;j++){
            if(v[i][j]==v[i-1][j]+1){
                // TF can't be possible  ( TF means i-1 th row will operated and ith row have no operations)
                v1[i]=true;
            }else if(v[i][j]==v[i-1][j]){
                // TT or FF can't possible
                v2[i]=true;
            }else if(v[i][j]+1==v[i-1][j]){
                //FT can't possible
                v3[i]=true;
            }
        }
    }

    for(int i=0;i<n;i++){
        if(v1[i] && v2[i] && v3[i]) return INF; // nothing is allow , so not possible
    }

    int dp1[n],dp2[n];
    dp1[0]=0;
    dp2[0]=a[0];
    for(int i=1;i<n;i++){
        if(v1[i] && v2[i]){ // FT allow
            dp1[i]=INF;
            dp2[i]=dp1[i-1]+a[i];
        }else if(v2[i] && v3[i]){ // TF allow
            dp1[i]=dp2[i-1];
            dp2[i]=INF;
        }
        else if(v1[i] && v3[i]){ // TT or FF allow
            dp1[i]=dp1[i-1];
            dp2[i]=dp2[i-1]+a[i];
        }else if(v1[i]){ // TT or FF or FT allow
            dp1[i]=dp1[i-1];
            dp2[i]=min(dp1[i-1],dp2[i-1])+a[i];
        }else if(v2[i]){ // TF or FT
            dp1[i]=dp2[i-1];
            dp2[i]=dp1[i-1]+a[i];
        }else if(v3[i]){ // TF or TT or FF allow
            dp1[i]=min(dp1[i-1],dp2[i-1]);
            dp2[i]=dp2[i-1]+a[i];
        }else{ // all allow 
            dp1[i]=min(dp1[i-1],dp2[i-1]);
            dp2[i]=min(dp1[i-1],dp2[i-1])+a[i];
        }
    }

    return min(dp1[n-1],dp2[n-1]);
}
void Solve()
{
    int n, x, r, d, m;
    cin>> n;
    vector<vector<int>> v(n,vector<int>(n));
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>v[i][j];
        }
    }
    vector<int> a(n),b(n);
    for(int i=0;i<n;i++) cin>> a[i];
    for(int i=0;i<n;i++) cin>> b[i];
    int row=solve(n,v,a);
    if(row>=INF){
        cout<<-1<<endl;
        return;
    }
    auto u=v;
    for(int i=0;i<n;i++){ // transpose the array to do the column operations
        for(int j=0;j<n;j++){
            u[i][j]=v[j][i];
        }
    }
    int col=solve(n,u,b);
    if(col>=INF){
        cout<<-1<<endl;
        return;
    }
    cout<<row+col<<endl;
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
        Solve();
    }

    auto end = chrono::high_resolution_clock::now();
    auto elapsed = chrono::duration_cast<chrono::nanoseconds>(end - begin);
    // cerr << "Time measured: " << elapsed.count() * 1e-9 << " seconds.\n";
    return 0;
}