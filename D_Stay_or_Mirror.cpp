#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define endl '\n'

void solve() {
    int n, s; 
    cin >> n;

    vector<int> v(n); 

    for (int i = 0; i < n; i++) {
        cin>> v[i];
    }
    int ans=0;
    for (int i = 1; i <= n; i++) {
        int pos=0;
        while(v[pos]!=i) pos++;
        ans+=min(pos,(int)v.size()-pos-1);
        v.erase(v.begin()+pos);
    }

    cout << ans << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    ll t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
