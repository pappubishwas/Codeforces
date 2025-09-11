#include <bits/stdc++.h>
using namespace std;
using ll=long long;
const int INF = 1e18;

void solve() {
    ll n,k;
    cin>> n>>k;
    vector<pair<ll,ll>> a(n);
    for(int i=0;i<n;i++){
        cin>> a[i].first;
    }
    for(int i=0;i<n;i++){
        cin>> a[i].second;
    }
    for(int i=0;i<n;i++){
        if(a[i].first>a[i].second){
            swap(a[i].first,a[i].second);
        }
    }
    ll res=0;
    sort(a.begin(),a.end());
    for(int i=0;i<n;i++){
        res+=abs(a[i].second-a[i].first);
    }
    ll mn=INF;
    for(int i=0;i<n-1;i++){
        if(a[i].second>=a[i+1].first){
            cout<<res<<"\n";
            return;
        }
        mn=min(mn,a[i+1].first-a[i].second);
    }
    cout<<res+2*mn<<"\n";

}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
