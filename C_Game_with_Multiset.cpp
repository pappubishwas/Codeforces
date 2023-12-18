#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    long long m;
    cin >> m;
    map<long long, long long> mp;
    vector<vector<long long>> v(m, vector<long long>(2));
    vector<long long> ans;

    for (int i = 0; i < m; i++) {
        cin >> v[i][0] >> v[i][1];
    }

    for (int i = 0; i < m; i++) {
        if (v[i][0] == 1) {
            long long x = pow(2, v[i][1]);
            if (mp.find(x) != mp.end()) {
                mp[x]++;
            } else {
                mp[x] = 1;
                ans.push_back(x);
            }
        } else {
            map<long long, long long> mp1 = mp;
            sort(ans.begin(), ans.end());
            long long w = v[i][1];
            bool flag = false;
            while (w > 0) {
                if (mp1[w] > 0) {
                    flag = true;
                    break;
                }
                long long t = -1;
                for (int i = ans.size() - 1; i >= 0; i--) {
                    if (w >= ans[i] && mp1[ans[i]]>0) {
                        t = ans[i];
                        break;
                    }
                }

                if (t != -1 && mp1[t]>0) {
                    long long t1 = mp1[t];
                    long long nt = w / t;
                    if (nt >= t1) {
                        w = w - t * t1;
                        mp1[t] = 0;
                    } else {
                        w = w - nt * t;
                        mp1[t] = t1 - nt;
                    }
                } else {
                    break;
                }
            }
            if (flag || w == 0) {
                cout << "YES" << endl;
            } else {
                cout << "NO" << endl;
            }
        }
    }

    return 0;
}
