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
    int n;
    cin >> n ;
    vector<vector<int>> pap(n,vector<int>(3)),part1,part2;
    for(int i=0;i<n;i++){
        cin>> pap[i][0] >> pap[i][1];
        pap[i][2]=i+1;
    }
    sort(pap.begin(),pap.end()); // sort by x coordinate
    for(int i=0;i<n;i++){ 
        if(i<n/2){
            part1.push_back({pap[i][1],pap[i][0],pap[i][2]}); // take smallest n/2 points based on x coordinate
        }else{
            part2.push_back({pap[i][1],pap[i][0],pap[i][2]}); // take largest n/2 points based on x coordinate
        }
    }
    sort(part1.begin(),part1.end()); // sort by y coordinate
    sort(part2.begin(),part2.end()); // sort by y coordinate
    for(int i=0;i<n/2;i++){// all pair between part1 and part2 will give same sum of distance for x axis for any combinations, now we will try to make y axis ditance maximum , so we will pair smallest y with largest y
        cout<< part1[i][2] << " " << part2[n/2-i-1][2] << endl;
    }
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