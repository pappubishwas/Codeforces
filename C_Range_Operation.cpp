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



void build(int idx,int l,int r,vector<int>& seg,vector<int>& pap){
    if(l==r) {
        seg[idx]=pap[l];
        return;
    }
    int mid=(l+r)/2;
    build(2*idx+1,l,mid,seg,pap);
    build(2*idx+2,mid+1,r,seg,pap);
    seg[idx]=seg[2*idx+1]+seg[2*idx+2];
}

void query(int idx,int l,int r,int n,int& res,vector<int>& seg,vector<int>& prefix){
    if(l>r){
        return;
    }
    int leftsum=prefix[l-1];
    int rightsum=prefix[n]-prefix[r];
    int midsum=(l+r)*(r-l+1LL);
    res=max(res,leftsum+rightsum+midsum);
    if(l==r) return;
    int mid=(l+r)/2;
    query(2*idx+1,l,mid,n,res,seg,prefix);
    query(2*idx+2,mid+1,r,n,res,seg,prefix);
}

// void solve()
// {
//     int n,a;
//     cin>> n;
//     vector<int> pap(n+1),segmentTree(4*n),prefix(n+2);
//     for(int i=1;i<=n;i++) {
//         cin>>pap[i];
//         prefix[i]+=prefix[i-1]+pap[i];
//     }
//     prefix[n+1]=prefix[n];

//     build(0,1,n,segmentTree,pap);
//     int res=LLONG_MIN;
//     query(0,1,n,n,res,segmentTree,prefix);
//     cout<<res<<endl;
// }


// total= prefix[l-1]+sum(l,r)+prefix[n]-prefix[r]
// sum(l,r)= (r-l+1)*(l+r) = r*r - l*l + l + r 
// total= (prefix[l-1] + l + l*l) + (r*r + r - prefix[r]) + prefix[n] 

void solve() {
    int n;
    cin >> n;

    vector<int> pref(n + 1, 0);
    for (int i = 1; i <= n; i++) {
        int x;
        cin >> x;
        pref[i] = pref[i - 1] + x;
    }

    int base = pref[n]; // total sum
    int ans = base; // without any operations
    int bestG = -INF;

    for (int r = 1; r <= n; r++) {
        int g = pref[r - 1] + r - r * r; // if it is l then gain will be this 
        bestG = max(bestG, g); // best gain for l from 1 to r  // keep sotring the best l 

        int h = -pref[r] + r * r + r; // gain value for if this is r value
        ans = max(ans, base + bestG + h);
    }

    cout << ans << endl;
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