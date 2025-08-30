#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const ll MOD = 1000000007;
ll add(ll a, ll b, ll m = MOD) { return ((a%m) + (b%m) + m) % m; }
ll sub(ll a, ll b, ll m = MOD) { return ((a%m) - (b%m) + m) % m; }
ll mul(ll a, ll b, ll m = MOD) { return ((a%m) * (b%m)) % m; }
ll modexp(ll a, ll e, ll m = MOD) {
    a %= m; ll r = 1;
    while (e) {
        if (e & 1) r = mul(r, a, m);
        a = mul(a, a, m);
        e >>= 1;
    }
    return r; 
}
ll inv(ll a, ll m = MOD) { return modexp(a, m - 2, m); }

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);

	int tc; cin >> tc;
	while(tc--) {
		ll a, b, k; cin >> a >> b >> k;
		ll n = (a-1)*k + 1;
		// m = n C a * k * (b-1) + 1
		ll m = 1;
		ll top = n, bot = 1;
		while(bot <= a) {
			m = mul(m, top);
			m = mul(m, inv(bot));
			top--; bot++;
		}
		m = mul(m, k); m = mul(m, b-1);
		m = add(m, 1);
		cout << n%MOD << " " << m << "\n";
	}

	return 0;
}