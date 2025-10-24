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

int binaryLength(int n)
{
    return 64 - __builtin_clzll(n);
}

struct pair_hash {
    size_t operator()(const pair<int, int>& p) const noexcept {
        return hash<long long>()(((long long)p.first << 32) ^ p.second);
    }
};

void Solve()
{
    int n, m, k;
    cin >> n;
    vector<int> a(n), b(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    int idxE = -1, cnt = 0;
    for (int i = 0; i < n; i++) {
        cin >> b[i];
        if (a[i] == b[i]) {
            cnt++;
            idxE = i;
        }
    }
    if (cnt > 1) {
        cout << -1 << endl;
        return;
    }
    vector<pair<int, int>> res;
    if (cnt == 1 && idxE != n / 2) {
        int mid = n / 2;
        swap(a[idxE], a[mid]);
        swap(b[idxE], b[mid]);
        res.push_back({min(idxE + 1, mid + 1), max(idxE + 1, mid + 1)});
    }
    unordered_map<pair<int, int>, set<int>, pair_hash> pos;
    for (int i = 0; i < n; i++) {
        int mn = min(a[i], b[i]);
        int mx = max(a[i], b[i]);
        pos[{mn, mx}].insert(i);
    }
    for (int i = 0; i < n / 2; i++) {
        int mn = min(a[i], b[i]);
        int mx = max(a[i], b[i]);
        if (pos[{mn, mx}].size() == 1) {
            cout << -1 << endl;
            return;
        }
        auto it = prev(pos[{mn, mx}].end());
        //cout<<*it<<endl;
        if (*it == n - i - 1) continue;
        res.push_back({*it + 1, n - i});
        int rm = n - i - 1;
        pos[{min(a[n - i - 1], b[n - i - 1]), max(a[n - i - 1], b[n - i - 1])}].erase(rm);
        pos[{min(a[n - i - 1], b[n - i - 1]), max(a[n - i - 1], b[n - i - 1])}].insert(*it);
        swap(a[*it], a[n - i - 1]);
        swap(b[*it], b[n - i - 1]);
    }

    cout << res.size() << endl;
    for (auto p : res) {
        cout << p.first << " " << p.second << endl;
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
    for (int i = 1; i <= t; i++) {
        // cout << "Case #" << i << ": ";
        Solve();
    }

    auto end = chrono::high_resolution_clock::now();
    auto elapsed = chrono::duration_cast<chrono::nanoseconds>(end - begin);
    // cerr << "Time measured: " << elapsed.count() * 1e-9 << " seconds.\n";
    return 0;
}
