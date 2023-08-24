#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define endl '\n'
void solve() {
    int n, m, c = 0;
    cin >> n >> m;
    string st[n];
    
    bool dp1 = false, dp2 = false, dp3 = false, dp4 = false;

    for (int i = 0; i < n; i++) {
        cin >> st[i];
    }

    for (int i = 0; i < m; i++) {  // Iterate over columns
        for (int j = 0; j < n; j++) {  // Iterate over rows
            if (st[j][i] == 'v' && !dp1) {
                dp1 = true;
                c++;
                break;
            } else if (st[j][i] == 'i' && dp1 && !dp2) {
                dp2 = true;
                c++;
                break;
            } else if (st[j][i] == 'k' && dp1 && dp2 && !dp3) {
                dp3 = true;
                c++;
                break;
            } else if (st[j][i] == 'a' && dp1 && dp2 && dp3) {
                dp4 = true;
                c++;
                break;
            }
        }
        if (c == 4)
            break;
    }

    if (c == 4)
        cout << "YES" << endl;
    else
        cout << "NO" << endl;
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