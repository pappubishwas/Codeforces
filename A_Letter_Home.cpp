#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve(){
        ll n, c,k;
        cin >> n >>k;
        vector<ll> a(n);
        ll mx=INT_MIN,mn=INT_MAX;
        for(int i=0;i<n;i++){
            cin>> c;
            mx=max(mx,c);
            mn=min(mn,c);
        }
        ll res= min((abs(mx-k)+mx-mn),(abs(k-mn)+mx-mn));
        cout<<res<<endl;
}

int main() {
    int t;
    cin >> t;
    while(t--) {
        solve();
    }
    return 0;
}


