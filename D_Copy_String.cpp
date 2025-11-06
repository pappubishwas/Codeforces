#include <iostream>
#include <string>
#include <vector>

using namespace std;

void solve() {
    int n, k_max;
    cin >> n >> k_max;
    string s, t;
    cin >> s >> t;

    if (s == t) {
        cout << 0 << endl;
        return;
    }

    if (s[0] != t[0]) {
        cout << -1 << endl;
        return;
    }

    string current_s = s;
    vector<string> operations_log;
    bool possible = false;

    for (int k = 1; k <= k_max; ++k) {
        string next_s = "";
        next_s += current_s[0]; // s'_1 = s_1

        for (int i = 1; i < n; ++i) {
            // Greedy choice:
            // 1. Prioritize keeping the current char if it matches target.
            // 2. Otherwise, check if the char from the left matches target.
            // 3. Otherwise (default), pull the char from the left.
            if (current_s[i] == t[i]) {
                next_s += current_s[i];
            } else if (current_s[i - 1] == t[i]) {
                next_s += current_s[i - 1];
            } else {
                // THE FIX:
                // Always propagate from the left on a total mismatch.
                next_s += current_s[i - 1]; 
            }
        }

        current_s = next_s;
        operations_log.push_back(current_s);

        if (current_s == t) {
            possible = true;
            cout << k << endl;
            for (const string& op_s : operations_log) {
                cout << op_s << endl;
            }
            break;
        }

        // Optimization: If the string didn't change, it's stuck.
        if (k > 0 && operations_log.size() > 1 && operations_log.back() == operations_log[operations_log.size() - 2]) {
             break;
        }
    }

    if (!possible) {
        cout << -1 << endl;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}