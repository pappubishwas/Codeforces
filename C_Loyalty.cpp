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
    cin >> n>>x;

    vector<int> pap(n),ans;
    for(int i=0;i<n;i++) cin>>pap[i];
    sort(begin(pap),end(pap));
    int l=0,r=n-1,sum=pap[n-1],res=0;
    k=1;
    
    while(l<=r){
        while(l<r && sum<k*x){
            sum+=pap[l];
            ans.push_back(pap[l]);
            l++;
        }
        if(sum>=k*x){
            res+=pap[r];
            ans.push_back(pap[r]);
            r--;
            if(l<=r){
                sum+=pap[r];
            }
            k++;
        }else{
            ans.push_back(pap[r]);
            r--;
        }
    }
    cout<<res<<endl;
    for(auto t:ans) cout<<t<<" ";
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