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
    vector<int> pap(n),odd,even;
    for(auto &p:pap){
        cin>>p;
        if(p%2)
        odd.push_back(p);
        else
        even.push_back(p);
    }
    sort(odd.begin(),odd.end());
    sort(even.begin(),even.end());
    if(n==1){
        cout<<pap[0]<<endl;
        return;
    }
    int on=odd.size()-1;
    int en=even.size()-1;
    int res=0;
    if(odd.size()==0){
        cout<<even[en]<<endl;
        return;
    }

    res=odd[on];
    on--;
    while (on>=0 && en>=0)
    {
        res+=(odd[on]-1);
        on--;
    }
    while(en>=0){
        res+=even[en];
        en--;
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