#include <bits/stdc++.h>
using namespace std;
#define gcd __gcd
#define ll long long
#define ld long double
#define endl '\n'

// ll gcd(ll a, ll b) {
//     if (a == 0) return b;
//     if (b == 0) return a;
//     return GCD(b, a % b);
// }

ll GCDN(vector<ll>& v, ll n) {
    ll temp = 0;
    for (size_t i = 1; i < n; i++) {
        temp = gcd(temp, v[i]-v[i-1]);
    }
    return temp;
}

void solve() {
    ll n, res = 0;
    cin >> n;
    vector<ll> vec(n);
    map<ll, ll> mp;
    
    for (size_t i = 0; i < n; i++) {
        cin >> vec[i];
        mp[vec[i]] = 1;
    }
    if(n==1){
        cout<<1<<endl;
        return;
    }
    sort(vec.begin(), vec.end());
    vector<ll> difference(n - 1);
    
    for (size_t i = 0; i < n - 1; i++) {
        difference[i] = vec[n - 1] - vec[i];
    }
    
    ll x = GCDN(vec,n);
    
    for (size_t i = 0; i < n - 1; i++) {
        res += (difference[i] / x);
    }
    
    ll temp = vec[n - 1];
    for (size_t i = 0; i < n; i++) {
        temp -= x;
        if (mp[temp] != 1) {
            cout << res + i + 1 << endl;
            return;
        }
    }
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
