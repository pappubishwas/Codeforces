#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define endl '\n'
void solve()
{
   ll n;
   cin>> n;
   vector<ll> arr(n,0);
   vector<ll> prefixMin(n,0);
   vector<ll> suffixMax(n,0);

   for(ll i=0;i<n;i++){
    cin>> arr[i];
    prefixMin[i]= min((i==0? LLONG_MAX : prefixMin[i-1]),arr[i]);
    //cout<< prefixMin[i]<<" ";
   }
   for(ll i=n-1;i>=0;i--){
    suffixMax[i]=max((i==n-1 ? 0: suffixMax[i+1]),arr[i]);
   }
   string t="";
   for(ll i=0;i<n;i++){
    if(arr[i]==prefixMin[i] || arr[i]==suffixMax[i]) t+='1';
    else t+='0';
   }
   cout<<t<<endl;
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