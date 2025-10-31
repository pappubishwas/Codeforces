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

int findOptimal(int need,int curr,vector<int>& b){
    int l=0,r=b.size()-1;
    int ans=INF;
    while(l<=r){
        int mid=(l+r)/2;
        int temp=b[mid]-curr;
        if(temp<=need){
            ans=temp;
            l=mid+1;
        }else{
            r=mid-1;
        }
    }
    return ans;
}

void solve()
{
    int n, m, k;
    cin >> n >> m ;
    vector<int> pap(n),b(m);
    for(auto& t:pap) cin>>t;
    for(auto& t:b) cin>>t;
    sort(begin(b),end(b));
    pap[n-1]=max(pap[n-1],b[m-1]-pap[n-1]);
    for(int i=n-2;i>=0;i--){
        int temp=findOptimal(pap[i+1],pap[i],b);
        if(pap[i]<=pap[i+1] && temp<=pap[i+1]){
            pap[i]=max(pap[i],temp);
        }else if(temp<=pap[i+1]) pap[i]=temp;
        if(pap[i]>pap[i+1]){
            cout<<"NO"<<endl;
            return;
        }
    }           
    cout<<"YES"<<endl;
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