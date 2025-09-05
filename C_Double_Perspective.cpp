#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define endl '\n'

void solve() {
    int n, s; 
    cin >> n;

    vector<pair<pair<int,int>,int>> v; 

    for (int i = 0; i < n; i++) {
        int x, y; 
        cin >> x >> y;  
        v.push_back({{x, -y}, i + 1});
    }

    sort(v.begin(), v.end());

    int mn = INT_MIN;
    vector<int> ans;

    for (int i = 0; i < n; i++) {
        if (v[i].first.first > mn) {
            mn = v[i].first.first;
            ans.push_back(v[i].second);
        }
    }

    cout << ans.size() << endl;
    for (auto x : ans) cout << x << " ";
    cout << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    ll t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
