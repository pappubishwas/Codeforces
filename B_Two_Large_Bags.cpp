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
int mod=998244353;

void solve() {
    int n;
    cin >> n;
    vector<int> pap(n);
    for(int i=0;i<n;i++) cin>>pap[i];
    sort(begin(pap),end(pap));
    if(pap[0]!=pap[1]){
        cout<<"No"<<endl;
        return;
    }
    int lastseen=pap[0];
    for(int i=2;i<n;i+=2){
        int a1=pap[i];
        int a2=pap[i+1];
        if(a1==a2){
            if(a1<=lastseen){
                lastseen++;
            }else{
                lastseen=a1;
            }
        }else{
            lastseen++;
            if(a1>lastseen || lastseen<a2){
                cout<<"No"<<endl;
                return;
            }
        }
    }
    cout<<"Yes"<<endl;
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