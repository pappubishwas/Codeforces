#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define endl '\n'
void solve() {
    long long n, m, c = 0;
    cin >> n;
    vector<long long> v;
    vector<long long> ans;
    for (long long i = 0; i < n; i++) {
        cin >> m;
        v.push_back(m);
    }
    ans.push_back(v[0]);
    for (long long i = 1; i < n; i++) {
        if (v[i - 1] > v[i]) {
            ans.push_back(v[i]);
            ans.push_back(v[i]);
        } else {
            ans.push_back(v[i]);
        }
    }
    cout << ans.size() << endl;
    for (long long i = 0; i < ans.size(); i++) {
        cout << ans[i] << " ";
    }
    cout << endl;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    ll t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}