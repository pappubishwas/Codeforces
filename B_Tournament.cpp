#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define endl '\n'
void solve()
{
    ll n,j,k;
    cin>> n>>j>>k;
    ll arr[n];
    for(ll i=0;i<n;i++){
        cin>>arr[i];
    }
    ll jth=arr[j-1];
    sort(arr,arr+n);
    if(k>=2 || (arr[n-1]==jth)){
        cout<<"YES"<<endl;
    }else{
        cout<<"NO"<<endl;
    }
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