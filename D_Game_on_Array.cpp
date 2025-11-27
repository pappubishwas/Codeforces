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
void solve() {
    int n;
    cin>> n;
    vector<int> pap(n);
    for(int i=0;i<n;i++) cin>> pap[i];
    map<int,int> mp;
    for(int i=0;i<n;i++) mp[pap[i]]++; // count element frequency
    int alice=0,bob=0;
    vector<int> oddFrq; // to store odd elements frequency , even number will be equally distributed
    for(auto [x,y]:mp){
        alice+= y*(x/2); // each player will get x/2 times of that element
        bob+= y*(x/2);
        if(x & 1){ // if frequency is odd then store it in oddFrq because this element will be taken by one more time by one player
            oddFrq.push_back(y);
        }
    }
    sort(oddFrq.rbegin(),oddFrq.rend()); // sort in descending order so that alice will get maximum frequency elements
    for(int i=0;i<oddFrq.size();i++){
        if(i%2==0) alice+=oddFrq[i]; // first time will take alice then bob
        else bob+=oddFrq[i];
    }
    cout<<alice<<" "<<bob<<endl;
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