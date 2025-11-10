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
    int n, k, x,m, y;
    cin >> n>>m;
    vector<int> quetions(m),participant(n);
    for(auto& t:participant) cin>>t;
    int kavin=participant[0];
    sort(begin(participant),end(participant));
    for(int i=0;i<m;i++) cin>> quetions[i];
    for(int i=0;i<m;i++){
        if(quetions[i]<=kavin){
            quetions[i]=1;
        }else{
            int cnt=participant.end() - lower_bound(begin(participant),end(participant),quetions[i]);
            quetions[i]=cnt+1;
        }
        //cout<<quetions[i]<<" ";
    }
    sort(begin(quetions),end(quetions));
    k=1;
    while(k<=m){
        int i=k-1;
        int res=0;
        while(i<m){
            res+=quetions[i];
            i+=k;
        }
        cout<<res<<" ";
        k++;
    }
    cout<<endl;
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