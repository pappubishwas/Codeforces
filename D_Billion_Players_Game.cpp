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
// void solve()
// {
//     int n, l,r;
//     cin >> n >> l>>r;
//     vector<int> pap(n);
//     for(int i=0;i<n;i++){
//         cin>> pap[i];
//     }
//     int total=accumulate(pap.begin(),pap.end(),0LL);
//     int md=total/n;
//     md=max(md,l);
//     md=min(md,r);
//     int ans1=0,ans2=0;
//     int md2=md+1;
//     if(md==r){
//         md2=md-1;
//     }
//     if(l==r){
//         md2=md;
//     }
//     for(int i=0;i<n;i++){
//         ans1+=abs(pap[i]-md);
//         ans2+=abs(pap[i]-md2);
//     }
//     cout<< min(ans1,ans2) << endl;
// }


void solve()
{
    int n, l,r;
    cin >> n >> l>>r;
    vector<int> pap(n);
    for(int i=0;i<n;i++){
        cin>> pap[i];
    }
    int ans=INF;
    while(l<=r){ // ternary search ,, we searching por minimum cost 
        int mid1=l+(r-l)/3; // middle point 1
        int mid2=r-(r-l)/3; // middle point 2
        int cost1=0,cost2=0;
        for(int i=0;i<n;i++){
            cost1+=abs(pap[i]-mid1);
            cost2+=abs(pap[i]-mid2);
        }
        if(cost1<cost2){ // ans is in left side
            r=mid2-1;
            ans=min(ans,cost1);
        }else if(cost1>cost2){ // ans is in right side
            l=mid1+1;
            ans=min(ans,cost2);
        }else{ // ans is in middle side
            ans=min(ans,cost1);
            l=mid1+1;
            r=mid2-1;
        }
    }
    cout<< ans << endl;
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