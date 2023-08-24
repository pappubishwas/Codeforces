void solve() {
    int n, m, c = 0;
    cin >> n >> m;
    string st[n];
    
    bool dp1 = false,dp2 = false, dp3 = false,dp4 = false;

    for (int i = 0; i < n; i++) {
        cin >> st[i];
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
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