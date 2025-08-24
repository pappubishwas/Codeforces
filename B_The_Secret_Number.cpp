#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    ll n;
    cin >> n;

    vector<ll> res;

    for (int k = 1; k <= 18; k++) {  
        ll d = 1 + (ll)pow(10, k);
        if (d > n) break;
        if (n % d == 0) {
            res.push_back(n / d);
        }
    }

    if (res.empty()) {
        cout << 0 << "\n";
    } else {
        sort(res.begin(), res.end());
        cout << res.size() << "\n";
        for (ll x : res) cout << x << " ";
        cout << "\n";
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) solve();
}
