#include <iostream>
#include <vector>
#include <utility>
using namespace std;

const int MOD = 1e9 + 7;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL), cout.tie(NULL);

    int T;
    cin >> T;
    while (T--) {
        long long n;
        cin >> n;
        vector<pair<long long, long long>> rng(n);
        for (int i = 0; i < n; i++)
            cin >> rng[i].first >> rng[i].second;

        long long low = 0, high = 1e9, mid;
        long long left, right, ans;
        while (low <= high) {
            mid = (low + high) >> 1;
            left = 0, right = 0;
            for (int i = 0; i < n; i++) {
                left = max(left - mid, rng[i].first);
                right = min(right + mid, rng[i].second);
                if (left > right)
                    break;
            }
            if (left <= right)
                ans = mid, high = mid - 1;
            else
                low = mid + 1;
        }
        cout << ans << endl;
    }
    return 0;
}
