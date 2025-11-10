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

// int ans(vector<int>& factor,int l,int r,int val){
//     if(l>r) return 0;
//     int m=(l+r)/2;
//     int left=lower_bound(factor.begin(),factor.end(),val/l)-factor.begin();
//     int right=lower_bound(factor.begin(),factor.end(),val/r)-factor.begin();
//     int mid=lower_bound(factor.begin(),factor.end(),val/m)-factor.begin();
//     if(left==mid && right==mid){
//         return left*(r-l+1);
//     }else if(left==mid){
//         return left*(m-l+1)+ans(factor,m+1,r,val);
//     }else if(right==mid){
//         return right*(r-m+1)+ans(factor,l,m-1,val);
//     }else{
//         return ans(factor,l,m,val)+ans(factor,m+1,r,val);
//     }
// }
void solve()
{
    int n, k, x,m, y,l1,l2,r1,r2;
    cin >> k>>l1>>r1>>l2>>r2;
    // vector<int> factor;
    // int exp=0;
    // while(true){
    //     int b=pow(k,exp);
    //     if(l1*b>=l2 && l1*b<=r2){
    //         factor.push_back(b);
    //     }
    //     if(l1*b>r2){
    //         break;
    //     }
    //     exp++;
    // }

    // int res=ans(factor,l1,r1,r2);

    int curr=1,res=0;
    while(curr<=1e9){
        int lb2=(l2+curr-1)/curr;
        int rb2=(r2)/curr;
        lb2=max(lb2,l1);
        rb2=min(rb2,r1);
        if(lb2<=rb2){
            res+=(rb2-lb2+1);
        }
        curr*=k;
    }
    cout<<res;
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