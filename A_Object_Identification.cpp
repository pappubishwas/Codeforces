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
    vector<int> pap(n),frq(n+1);
    for(int i=0;i<n;i++) {
        cin>>pap[i];
        frq[pap[i]]++;
    }

    auto query=[&](int x,int y){
        cout<<"? "<<x<<" "<<y<<endl;
        int val;
        cin>>val;
        return val;
    };

    for(int i=1;i<=n;i++){
        if(frq[i]==0){
            int y=i-1;
            if(y==0) y=i+1;
            int q=query(i,y);
            if(q==0){
                cout<<"! A"<<endl;
            }else{
                cout<<"! B"<<endl;
            }
            return;
        }
    }

    int p1,p2;
    for(int i=0;i<n;i++){
        if(pap[i]==1) p1=i+1;
        if(pap[i]==n) p2=i+1;
    }

    int q1=query(p1,p2);
    int q2=query(p2,p1);
    if(q1==q2 && q1+1>=n){
        cout<<"! B"<<endl;
    }else{
        cout<<"! A"<<endl;
    }
    // cout<<"? 1 2"<<endl;
    // int ans1,ans2;
    // cin>>ans1;
    // cout<<"? 2 1"<<endl;
    // cin>> ans2;
    // if(ans1==ans2 && ans1!=0){
    //     cout<<"! B"<<endl;
    // }else {
    //     cout<<"! A"<<endl;
    // }
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