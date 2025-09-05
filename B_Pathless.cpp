#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define endl '\n'
void solve()
{
int n, s; cin >> n >> s;
		int sm = 0;
		int cnt[3] = {0, 0, 0};
		for(int i = 0; i < n; i++) {
			int x; cin >> x; sm += x;
			cnt[x]++;
		}
		if(sm > s || s - sm == 1) {
			while(cnt[0]--) cout << "0 ";
			while(cnt[2]--) cout << "2 ";
			while(cnt[1]--) cout << "1 ";\
			cout << "\n";
		}
		else cout << "-1\n";
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