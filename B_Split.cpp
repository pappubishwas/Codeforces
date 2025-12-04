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
void Solve()
{
    int n, x, r, d, m;
    cin>> n;
    vector<int> pap(2*n);
    map<int,int> frq;
    for(int i=0;i<2*n;i++){
        cin>>pap[i];
        frq[pap[i]]++;
    }
    int ans=0,oddSum=0,zeroRem=0,twoRem=0,evenCount=0;
    for(auto& it:frq){
        int count=it.second;
        if(count==2 || (count%2==0 && (count/2)%2)){
            ans+=2;
        }else if(count%2){
            ans++;
            oddSum+=count;
        }else{
            if(count%4==0) zeroRem++;
            else twoRem++;
            evenCount++;
        }
    }
    if((oddSum<2) && (zeroRem%2 || twoRem%2)) evenCount--;
    ans+=evenCount*2;
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
        Solve();
    }

    auto end = chrono::high_resolution_clock::now();
    auto elapsed = chrono::duration_cast<chrono::nanoseconds>(end - begin);
    // cerr << "Time measured: " << elapsed.count() * 1e-9 << " seconds.\n";
    return 0;
}