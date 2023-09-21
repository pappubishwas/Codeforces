
#include <bits/stdc++.h>
#include<cstring>
using namespace std;
#define ll long long
#define ld long double
#define endl '\n'
void solve() {
    ll n, k, count = 0, p, j = 0, i = 0;
    cin >> n >> k;
    vector<ll> v;
    for (i = 0; i < n; i++) {
        cin >> p;
        v.push_back(p);
    }
    ll l = 1, h = k + 1, mid = 1;
    while (l <= h) {
        mid = (l + h) / 2;
        ll totalSum = 0;
        for (i = 0; i < n; i++) {
            if (mid < v[i])
                totalSum += (v[i] - mid);
        }
        if (totalSum == k) {
            break;
        } else if (totalSum < k)
            l = mid;
        else
            h = mid;
    }
    cout << mid << endl;
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