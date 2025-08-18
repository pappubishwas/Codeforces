#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve(){
        ll n, c;
        cin >> n ;
        vector<ll> a(n);
        for(int i = 0; i < n; i++) {
            cin >> a[i];
        }
        ll mn=2*a[0];
        for(int i=1;i<n;i++){
            if(a[i]>=mn){
                cout<<"NO"<<endl;
                return;
            }
            mn=min(mn,2*a[i]);
        }
        cout<<"YES"<<endl;
}

int main() {
    int t;
    cin >> t;
    while(t--) {
        solve();
    }
    return 0;
}
