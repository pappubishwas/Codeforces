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

vector<vector<int>> dir={{0,1},{1,0},{-1,0},{0,-1}};

void solve()
{
    int n,k;
    cin>>n>>k;
    map<int,int> starta,endb;
    set<int> unique;

    for(int i=0;i<n;i++){
        int t;
        cin>>t;
        unique.insert(t); // storing all unique values....
        starta[t]++; // starting counts of elements ..
    }
    for(int i=0;i<n;i++){
        int t;
        cin>>t;
        unique.insert(t);
        endb[t]++; // ending counts of elements..
    }

    int ans=0,active=0,remaining=n;
    for(int price:unique){ // we take all unique values(means only the starting or ending of range) because middle value doest not increase result because number of active value and number of remaining value did not change
        if(active<=k){
            ans=max(ans,price*remaining);
        }
        active+=starta[price]; // next price greater than of current price, so this value will be active to give negative review
        active-=endb[price]; //if some value has this price they won't be consider for next price as they will not buy
        remaining-=endb[price]; // total values will be considered to buy either give positive or negative review
    }
    cout<<ans<<endl;
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