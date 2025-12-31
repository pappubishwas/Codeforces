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
const int mod = 998244353;
const int MOD = 1e9 + 7;
int rndRange(int l, int r) { return RNG() % (r - l + 1) + l; }
int powerl(int a, int b)
{
    int res = 1;
    while (b)
    {
        if (b & 1)
            res = res * a % mod;
        a = a * a % mod;
        b >>= 1;
    }
    return res;
}
int inMod(int a)
{
    return powerl(a, mod - 2);
}
int sol(vector<int>& a, vector<int>& b)
{
}
void Solve()
{
    int n,m,k;
    cin >> n>>m>>k;
    vector<int> pap(m);
    vector<pair<int,int>> tan;
    priority_queue<long long> pq;
    for(int i=0;i<m;i++){
        cin>>pap[i];
    }
    int total=0;
    for(int i=0;i<n;i++){
        int x,y,z;
        cin>>x>>y>>z;
        total+=y;
        tan.push_back({x,z-y});
    }
    int curr=k-total;
    // if(curr<=0){
    //     cout<<0<<endl;
    //     return;
    // }
    sort(pap.begin(),pap.end());
    sort(tan.begin(),tan.end());

    int idx = 0;
    int count = 0;
    multiset<int> mt;
    for (int i = 0; i < m; ++i) {
        while (idx < n && tan[idx].first <= pap[i]) {
            pq.push(tan[idx].second);
            idx++;
        }
        if (!pq.empty()) {
            pq.pop();
            count++;
        }
    }

    while (idx < n) {
        mt.insert(tan[idx].second);
        idx++;
    }

    while (!pq.empty()) {
        mt.insert(pq.top());
        pq.pop();
    }
    for (auto cost : mt) {
        if (curr >= cost) {
            curr -= cost;
            count++;
        } else {
            break; 
        }
    }

    cout << count << "\n";
}
int32_t main()
{
    auto begin = chrono::high_resolution_clock::now();
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t = 1;
    cin >> t;

    for (int i = 1; i <= t; i++)
    {
        Solve();
    }

    auto end = chrono::high_resolution_clock::now();
    auto elapsed = chrono::duration_cast<chrono::nanoseconds>(end - begin);
    return 0;
}