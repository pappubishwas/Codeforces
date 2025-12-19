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
void Solve()
{
    int n,m;
    cin>>n;
    vector<int> a(n),b(n);
    for(int i=0;i<n;i++) cin>>a[i];
    for(int i=0;i<n;i++) cin>>b[i];
    int cnt=0;
    for(int i=0;i<n;i++) if(a[i]<b[i]) cnt++;
    if(cnt==0) cout<<"YES"<<endl;
    else if(cnt>=2) cout<<"NO"<<endl;
    else{
        int need=0;
        for(int i=0;i<n;i++) if(a[i]<b[i]) need=b[i]-a[i];
        for(int i=0;i<n;i++){
            if(a[i]>=b[i] && a[i]-need<b[i]){
                cout<<"NO"<<endl;
                return;
            }
        }
        cout<<"YES"<<endl;
    }

}

int32_t main()
{
    auto begin = chrono::high_resolution_clock::now();
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t = 1;
    cin >> t;

    for (int i = 1; i <= t; i++)
    {
        Solve();
    }

    auto end = chrono::high_resolution_clock::now();
    auto elapsed = chrono::duration_cast<chrono::nanoseconds>(end - begin);
    return 0;
}