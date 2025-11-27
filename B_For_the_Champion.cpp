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
void solve() {
    int n;
    cin>> n;
    int k=1e9;
    int a=-INF,b=-INF;
    for(int i=0;i<n;i++){
        int x,y;
        cin>> x>> y;
        a=max(a,x+y);
        b=max(b,x-y);
    }
    int x;
    cout<<"? U "<<k<<endl;
    cin>> x;
    cout<<"? U "<<k<<endl;
    cin>> x;
    cout<<"? R "<<k<<endl;
    cin>> x;
    cout<<"? R "<<k<<endl;
    cin>> x;
    cout<<"? R "<<k<<endl;
    cin>> x;
    int p=a+x;
    cout<<"? D "<<k<<endl;
    cin>> x;
    cout<<"? D "<<k<<endl;
    cin>> x;
    cout<<"? D "<<k<<endl;
    cin>> x;
    cout<<"? D "<<k<<endl;
    cin>> x;
    int q=b+x;
    cout<<"! "<<(p+q-10*k)/2<<" "<<(p-q)/2<<endl;

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