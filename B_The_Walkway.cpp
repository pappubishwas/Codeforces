#include <iostream>
#include <vector>
using namespace std;

long long q, w, e, r, t, y, u, arr[100010], arr2[100010];

vector<long long> v;

int main() {
	cin.tie(0)->sync_with_stdio(false);
	cin >> q;
	while (q--) {
		cin >> w >> e >> r;
		v.resize(e);
		for (int i = 0; i < e; i++) {
			cin >> v[i];
		}
		if (v[0] == 1) {
			arr[0] = 1;
		}
		else {
			arr[0] = 1 + (v[0] - 2) / r + 1;
		}
		t = arr[0];
		for (int i = 1; i < e; i++) {
			arr[i] = (v[i] - v[i - 1] - 1) / r + 1;
			t += arr[i];
		}
		arr[e] = (w - v[e - 1]) / r;
		t += arr[e];
		arr2[0] = 1 + (v[1] - 2) / r + 1;
		for (int i = 1; i + 1 < e; i++) {
			arr2[i] = (v[i + 1] - v[i - 1] - 1) / r + 1;
		}
		arr2[e - 1] = (w - v[e - 2]) / r;
		y = arr2[0] - arr[0] - arr[1];
		u = 1;
		for (int i = 1; i < e; i++) {
			if (y == arr2[i] - arr[i] - arr[i + 1]) {
				++u;
			}
			if (y > arr2[i] - arr[i] - arr[i + 1]) {
				y = arr2[i] - arr[i] - arr[i + 1];
				u = 1;
			}
		}
		cout << t + y << " " << u << '\n';
	}
	return 0;
}