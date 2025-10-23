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

int binaryLength(int n){
    return 64 - __builtin_clzll(n);
}

void Solve()
{
    int n, q,x,a,b;
    cin>> n>> q;
    vector<int> pap(n+1),bls(n+1),fight(n+1);
    for(int i=1;i<=n;i++){
        cin>>pap[i];
        bls[i]=binaryLength(pap[i])-1;
        if(pap[i] & pap[i]-1){ // not power of 2
            if(pap[i]-1 & pap[i]-2){ // not power of 2 plus 1
                bls[i]++;
            }else{
                fight[i]=1;
            }
        }
        bls[i]+=bls[i-1];
        fight[i]+=fight[i-1];
    }
    while(q--){
        int l,r;
        cin>>l>>r;
        int totalBls=bls[r]-bls[l-1];
        int totalFights=fight[r]-fight[l-1]; // number of elsements which are power of 2 plus 1
        int ans= totalBls + totalFights/2; 
        cout<<ans<<endl;
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
        Solve();
    }

    auto end = chrono::high_resolution_clock::now();
    auto elapsed = chrono::duration_cast<chrono::nanoseconds>(end - begin);
    // cerr << "Time measured: " << elapsed.count() * 1e-9 << " seconds.\n";
    return 0;
}