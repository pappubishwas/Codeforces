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
    int n, m, x, len;
    cin >> n;
    vector<vector<int>> pap(2, vector<int>(n));
    vector<pair<int, int>> minmaxup(n), minmaxd(n);
    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> pap[i][j];
        }
    }
    int mn = LLONG_MAX, mx = LLONG_MIN;
    for (int i = 0; i < n; i++)
    {
        mn = min(mn, pap[0][i]);
        mx = max(mx, pap[0][i]);
        minmaxup[i].first = mn;
        minmaxup[i].second = mx;
        
    }
    mn = LLONG_MAX;
    mx = LLONG_MIN;
    for (int i = n - 1; i >= 0; i--)
    {
        mn = min(mn, pap[1][i]);
        mx = max(mx, pap[1][i]);
        minmaxd[i].first = mn;
        minmaxd[i].second = mx;
        //cout<<mn<<" "<<mx<<endl;
    }
    multiset<int> left, right;
    mn = min(minmaxup[0].first, minmaxd[0].first);
    mx = max(minmaxup[0].second, minmaxd[0].second);
    int res = (mn) * (2 * n - mx + 1);
    left.insert(mn);
    right.insert(mx);
    for (int i = 1; i < n; i++)
    {
        mn = min(minmaxup[i].first, minmaxd[i].first);
        mx = max(minmaxup[i].second, minmaxd[i].second);
        int temp1=(mn-(*left.rbegin()))*(2*n-mx+1);
        int temp2=((*right.begin())-mx)*(mn);
        res+=max(0LL,temp1);
        res+=max(0LL,temp2);
        left.insert(mn);
        right.insert(mx);
    }
    cout<<res<<endl;
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