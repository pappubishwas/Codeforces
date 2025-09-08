#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define endl '\n'

void solve() {
    ll n, s; 
    cin >> n;

    vector<ll> v(n); 

    for (int i = 0; i < n; i++) {
        cin>> v[i];
    }
    ll ans=0;
    for (int i = 1; i < n; i+=2) {
        ll right= i+1<n ? v[i+1] : 0;
        ll left= v[i-1];
        ll sum=left+right;
        if(v[i]<sum) {
            ll diff=sum-v[i];
            ans+=diff;
            // if(right>=v[i]){
            //     diff-=(right-v[i]);
            //     right-=(right-v[i]);
            //     if(right>0 && diff>0){
            //         diff--;
            //         right--;
            //     }
            // }
            // left-=diff;
            // if(i+1<n) v[i+1]=right;
            // v[i-1]=left;
            if(left>v[i]){
                diff-=(left-v[i]);
            }
            right-=diff;
            if(i+1<n) v[i+1]=right;
        }
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
