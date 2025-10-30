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

bool findAns(vector<int>& pap,vector<int>& idx,string str,int limit,int k){
    int need=0;
    int n=pap.size(),i=0;
    while(i<n){
        bool flag=false;
        if(str[i]=='B' && pap[i]>limit){
            while(i+1<n && (str[i+1]=='B' || pap[i+1]<=limit)) i++;
            need++;
            flag=true;
        }
        i++;
    }
    return need<=k;
}

void solve()
{
    int n,k;
    cin>>n>>k;
    string s;
    cin>> s;
    vector<int> pap(n);
    for(auto &t:pap) cin>>t;
    vector<int> blueidx;
    int ans=1e9;
    int l=0,r=1e9;
    while(l!=r){
        int mid=(l+r)/2;
        if(findAns(pap,blueidx,s,mid,k)){
            r=mid;
        }else{
            l=mid+1;
        }
    }
    cout<<l<<endl;
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