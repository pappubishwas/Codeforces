#include <bits/stdc++.h>
using namespace std;

#define fastIO                                                                 \
    ios::sync_with_stdio(false);                                               \
    cin.tie(NULL);                                                             \
    cout.tie(NULL);                                                            \
    cout.precision(numeric_limits<double>::max_digits10);

int query(int x, vector<int> vec) {
    cout << "? " << x << ' ' << vec.size() << ' ';
    for (auto i : vec)
        cout << i << ' ';
    cout << endl;
    int ans;
    cin >> ans;
    return ans;
} // n

void CoderAbhi27() {
    int n;
    cin >> n;
    vector<vector<int>> vec(n + 1);
    // vec[i] -> list of x for which ans to query is i
    vector<int> v;
    for (int i = 1; i <= n; i++)
        v.push_back(i); // n
    for (int i = 1; i <= n; i++) {
        vec[query(i, v)].push_back(i); // n
    } // n*n
    vector<int> ans;
    int l = -1;
    for (int i = n; i >= 1; i--) {
        if (vec[i].empty())
            continue;
        if (l == -1) {
            ans.push_back(vec[i][0]);
            l = vec[i][0];
            continue;
        }
        for (auto j : vec[i]) {
            if (query(l, {l, j}) == 2) {
                ans.push_back(j);
                l = j;
                break;
            }
        }
    }
    cout << "! " << ans.size() << ' ';
    for (auto i : ans)
        cout << i << ' ';
    cout << endl;
}

// tc : O(n^2)
// sc : O(n)

int32_t main() {
    fastIO;

    int t = 1;
    cin >> t;
    while (t--) {
        CoderAbhi27();
    }
    return 0;
}