#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>
#include <map>
using namespace std;

int ask_query(int l, int r) {
    cout << "? " << l << " " << r << endl;
    int mex;
    cin >> mex;
    if (mex == -1) {
        exit(0);
    }
    return mex;
}

void solve() {
    int n, q;
    cin >> n >> q;

    vector<pair<int, int>> ranges(q);
    for (int i = 0; i < q; ++i) {
        cin >> ranges[i].first >> ranges[i].second;
    }

    int pos_0 = -1;
    pair<int, int> pos_0_range = {-1, -1};

    for (int i = 1; i <= n - 1; i += 2) {
        int mex = ask_query(i, i + 1);
        if (mex >= 1) {
            pos_0_range = {i, i + 1};
        }
    }
    if (n % 2 != 0) {
        int mex = ask_query(n, n);
        if (mex >= 1) {
            pos_0_range = {n, n};
        }
    }

    if (pos_0_range.first == -1) {
        pos_0 = 1;
    } else if (pos_0_range.first == pos_0_range.second) {
        pos_0 = pos_0_range.first;
    } else {
        int i = pos_0_range.first;
        int mex_i = ask_query(i, i);
        if (mex_i == 1) pos_0 = i;
        else pos_0 = i + 1;
    }

    int min_l = n + 1;
    int max_r = 0;
    bool found_containing_range = false;

    for (int i = 0; i < q; ++i) {
        if (ranges[i].first <= pos_0 && ranges[i].second >= pos_0) {
            min_l = min(min_l, ranges[i].first);
            max_r = max(max_r, ranges[i].second);
            found_containing_range = true;
        }
    }

    int ans = 0;
    if (found_containing_range) {
        ans = ask_query(min_l, max_r);
    }

    map<pair<int, int>, int> memo;
    int max_mex = 0;

    for (int i = 1; i <= n - 1; i += 2) {
        int mex = ask_query(i, i + 1);
        memo[{i, i + 1}] = mex;
    }
    if (n % 2 != 0) {
        int mex = ask_query(n, n);
        memo[{n, n}] = mex;
    }

    vector<pair<int, int>> ranges_to_check;
    for(int i=0; i<q; ++i) {
        if(memo.count(ranges[i])) {
            max_mex = max(max_mex, memo[ranges[i]]);
        } else {
            ranges_to_check.push_back(ranges[i]);
        }
    }

    sort(ranges_to_check.begin(), ranges_to_check.end(), [](const pair<int, int>& a, const pair<int, int>& b) {
        return (a.second - a.first) > (b.second - b.first);
    });

    if (ranges_to_check.size() > 0) {
        int mex = ask_query(ranges_to_check[0].first, ranges_to_check[0].second);
        max_mex = max(max_mex, mex);
    }
    if (ranges_to_check.size() > 1) {
        if (ranges_to_check[1] != ranges_to_check[0]) {
             int mex = ask_query(ranges_to_check[1].first, ranges_to_check[1].second);
             max_mex = max(max_mex, mex);
        }
    }

    cout << "! " << max_mex << endl;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
