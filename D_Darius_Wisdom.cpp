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

void swappos(set<int> &ones, set<int> &twos, vector<pair<int, int>> &ans)
{
    while (!ones.empty() && !twos.empty() && *ones.rbegin() > *twos.begin())
    {
        int val1 = *ones.rbegin();
        int val2 = *twos.begin();
        ones.erase(val1);
        twos.erase(val2);
        ones.insert(val2);
        twos.insert(val1);
        ans.push_back({val2, val1});
    }
}

void solve()
{
    int n, m, v, k;
    cin >> n;
    vector<int> pap(n + 1);
    set<int> zeros, ones, twos;
    for (int i = 1; i <= n; i++)
    {
        cin >> pap[i];
        if (pap[i] == 1)
            ones.insert(i);
        if (pap[i] == 0)
            zeros.insert(i);
        if (pap[i] == 2)
            twos.insert(i);
    }
    vector<pair<int, int>> ans;
    int last = -1;
    while (last != ans.size() && ans.size() < n)
    {
        last = ans.size();
        swappos(ones,twos,ans);
        swappos(zeros,ones,ans);
        //swappos(ones,twos);
    }
    cout << ans.size() << endl;
    for (auto &it : ans)
    {
        cout << it.first << " " << it.second << endl;
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