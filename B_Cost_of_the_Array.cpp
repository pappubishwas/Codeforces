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
    int n, m, k;
    cin >> n >>k;
    vector<int> pap(n);
    for(int i=0;i<n;i++) cin>>pap[i];
    int flag=false;
    int start=n-k+1;
    while(start>0){
        if(pap[start]>1){
            flag=true;
            break;
        }
        start--;
    }
    if(flag){
        cout<<1<<endl;
        return;
    }
    if(n-k>=1){
        cout<<2<<endl;
        return;
    }
    int ans=1;
    start=1;
    while(start<n){
        if(ans==pap[start]){
            ans++;
        }else{
            cout<<ans<<endl;
            return;
        }
        start+=2;
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


