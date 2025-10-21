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

void Solve()
{
    int n, q;
    cin >> n;
    vector<int> pap(n);
    for(auto &p:pap){
        cin>>p;
    }
    int z=0,o=0,t=0,tr=0,f=0;
    for(int i=0;i<n;i++){
        if(pap[i]==0)z++;
        if(pap[i]==1)o++;
        if(pap[i]==2)t++;
        if(pap[i]==3)tr++;
        if(pap[i]==5)f++;
        if(z>=3 && o>=1 && t>=2 && tr>=1 && f>=1){
            cout<<i+1<<endl;
            return;
        }
    }
    cout<<0<<endl;
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