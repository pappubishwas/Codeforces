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
        ll ans=1;
        vector<ll> dp(n,0);
        dp[0]=1;
        for(int i=1;i<n;i++){
            if(a[i]>a[i-1]) dp[i]=dp[i-1]+1;
            else dp[i]=dp[i-1]+i+1;
            ans+=dp[i];
        }
        cout<<ans<<endl;
}

int main() {
    int t;
    cin >> t;
    while(t--) {
        solve();
    }
    return 0;
}
