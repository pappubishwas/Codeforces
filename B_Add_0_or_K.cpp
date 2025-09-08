#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define endl '\n'

void solve() {
    ll n, s,k; 
    cin >> n>>k;

    vector<ll> v(n); 

    for (int i = 0; i < n; i++) {
        cin>> v[i];
    }
    if(k%2==1){
        for(int i=0;i<n;i++) {
            
            if(v[i]%2==1) v[i]+=k;
            cout << v[i] << " ";
        }
        return;
    }
    ll ans=0;
    for (int i = 0; i < n; i++) {
        ll mod= v[i] % (k+1);
        v[i]+= mod*k;
        cout << v[i] << " ";
    }
    cout << endl;
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
