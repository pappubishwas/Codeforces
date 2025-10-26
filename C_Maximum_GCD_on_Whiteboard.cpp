#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
mt19937_64 RNG(chrono::steady_clock::now().time_since_epoch().count());
template <class T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;


int count_in_sorted(const vector<int>& a, int val) {
    auto lower = lower_bound(a.begin(), a.end(), val);  // first element >= val
    if (lower == a.end() || *lower != val) { // val not found or lower greater than val
        return 0;
    }
    auto upper = upper_bound(a.begin(), a.end(), val); // first element > val or in array there is aleast one value exist that is equal to val
    return distance(lower, upper); // count of elements equal to val
}

void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    sort(a.begin(), a.end()); // sorted the array to find cost easily by log(n) time

    for (int d = n; d >= 1; --d) {
        auto it = lower_bound(a.begin(), a.end(), 4 * d); // first element >= 4d
        int total_count_less_than_4d = distance(a.begin(), it); // count of elements < 4d

        int multiples_count = 0;
        multiples_count += count_in_sorted(a, d); // count of elements equal to d
        if (2 * d <= n) {
            multiples_count += count_in_sorted(a, 2 * d); // count of elements equal to 2d
        }
        if (3 * d <= n) {
            multiples_count += count_in_sorted(a, 3 * d); // count of elements equal to 3d  
        }

        int cost = total_count_less_than_4d - multiples_count; // elements < 4d but not multiples of d

        if (cost <= k) {
            cout << d << "\n";
            return;
        }
    }
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
