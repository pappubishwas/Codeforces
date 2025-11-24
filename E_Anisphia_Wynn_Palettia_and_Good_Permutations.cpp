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
    cin >> n;

    vector<int> v2, v3, other; // logic is , for every others element thier will be two elements from v2 or v3 to make the good permutation
    for (int i = 1; i <= n; i++) {
        if (i % 2 == 0) v2.push_back(i); // n/2 numbers
        else if (i % 3 == 0) v3.push_back(i); // n/3 -n/6 numbers
        else other.push_back(i); // n- n/2 - (n/3 - n/6) = n/3 numbers
    }

    vector<int> ans;

    while (v2.size() >= 2 && !other.empty()) { // for each two pair with one others
        ans.push_back(v2.back()); v2.pop_back();
        ans.push_back(v2.back()); v2.pop_back();
        ans.push_back(other.back()); other.pop_back();
    }

    while (v3.size() >= 2 && !other.empty()) { // for each two pair with one others
        ans.push_back(v3.back()); v3.pop_back();
        ans.push_back(v3.back()); v3.pop_back();
        ans.push_back(other.back()); other.pop_back();
    }

    while (!v2.empty()) {
        ans.push_back(v2.back());
        v2.pop_back();
    }
    while (!v3.empty()) {
        ans.push_back(v3.back());
        v3.pop_back();
    }
    while (!other.empty()) {
        ans.push_back(other.back());
        other.pop_back();
    }

    for (int i = 0; i < n; i++) {
        cout << ans[i] << (i + 1 == n ? "" : " ");
    }
    cout << "\n";
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