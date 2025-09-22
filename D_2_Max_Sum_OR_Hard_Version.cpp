#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;
#define INF(t) numeric_limits<t>::max()

int pow_log2(int x) {
	return 1 << (31 - __builtin_clz(x));
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);

	int tc; cin >> tc;
	while(tc--) {
		int l, r; cin >> l >> r;
		vector<int> ans(r-l+1);
		map<int, int> pos;
		for(int p = 0, i = l; i <= r; i++, p++) {
			ans[p] = i;
			pos[i] = p;
		}

		vector<bool> done(r-l+1, false);
		for(int j = 2*pow_log2(r); j >= 1; j /= 2) {

			for(int i = r; i >= l; i--) {
				if(done[pos[i]]) continue;
				int x = j - 1;
				int comp = x ^ i;
				if(comp < l || comp > r || done[pos[comp]]) continue;
				done[pos[i]] = done[pos[comp]] = true;
				//swap(pos[i], pos[comp]);
				swap(ans[pos[i]], ans[pos[comp]]);
			}
		}

		ll anss = 0;
		for(int p = 0, i = l; i <= r; i++, p++) {
			anss += (ans[p] | i);
		}

		cout << anss << "\n";
		for(auto &x : ans) cout << x << " ";
		cout << "\n";
	}

	return 0;
}