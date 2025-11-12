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

int query(int l,int r){
    cout<<"? "<<l<<" "<<r<<endl;
    int ans;
    cin>>ans;
    return ans;
}

void solve()
{
    int n, m, x, k,q;
    cin >> n;
    vector<int> a(n);
    int f1=query(1,n);
    if(f1==0){
        cout<<"! IMPOSSIBLE"<<endl;
        return;
    }
    for(int i=1;i<n;i++){
        a[i]=query(1,i+1);
    }

    int j=0;
    while(a[j]==0) j++;
    string s(n,'0');
    for(int i=0;i<j-a[j];i++){
        s[i]='1';
    }
    for(int i=j;i<n;i++){
        s[i]=(a[i]>a[i-1]) ? '1':'0';
    }
    cout<<"! "<<s<<endl;
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