#include <bits/stdc++.h>
using namespace std;
#define int long long
#define INF (int)1e18

mt19937_64 RNG(chrono::steady_clock::now().time_since_epoch().count());

int leftmostBit(int n) {
    for (int i = 31; i >= 0; i--) {
        if (((n >> i) & 1) == 1) {
            return i + 1;
        }
    }
    return 1;
}

void Solve() {
    int a, b;
    cin >> a >> b;
    vector<int> pap;
    if(a==b){
        cout<<0<<endl;
        return;
    }
    if (leftmostBit(a) < leftmostBit(b))
        cout << -1 << endl;
    else {
        for (int i = 0; i < 32; i++) {
            if (((a >> i) & 1) != ((b >> i) & 1)) {
                pap.push_back(1 << i);
            }
        }
        
        cout << pap.size() << endl;
        for (auto &p : pap) cout << p << " ";
        cout << endl;
    }
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) Solve();
    return 0;
}
