#include <bits/stdc++.h>
#include <cstring>
using namespace std;
#define ll long long
#define ld long double
#define endl '\n'
void solve()
{
int n;
cin>>n;
int a[n],b[n],c=0,q=0;
for(int i=0;i<n;i++){
    cin>>a[i]>>b[i];
}
for(int i=0;i<n;i++){
    if(a[i]<=10)
    if(q<b[i]){ 
        q=b[i];
        c=i+1;
    }
}
cout<<c<<endl;
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