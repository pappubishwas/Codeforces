#include <bits/stdc++.h>

#define ll long long
using namespace std;
const ll INF = 1e9;
int main() {
    vector<vector<int>> t(21, vector<int> (21));
    char c;
    for (int i = 0; i < 21; ++i) {
        for (int j = 0; j < 21; ++j) {
            cin >> c;
            t[i][j] = c - '0';
        }
    }
    ll ans = 0;
    for (int i = 0; i < 18; ++i) {
        for (int j = 0; j < 18; ++j) {
            ll sum = 0;
            for (int l = 0; l < 4; ++l) {
                for (int r = 0; r < 4; ++r) {
                    sum += t[i + l][j + r];
                }
            }
            ans = max(ans, sum);
        }
    }
    cout << ans;
}