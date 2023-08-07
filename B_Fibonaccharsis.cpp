#include <bits/stdc++.h>
#include <cstring>
using namespace std;
#define ll long long
#define ld long double
#define endl '\n'


void solve()
{
int c=0,k,n,t,k1,k2,k3,l=0;
cin>>n>>k;
if(n%2==0) t=n/2;
else t=(n+1)/2;
if((n==1 && k==3) || (n==2 && k<=4)) cout<<1<<endl;
else{
for (int i=t;i<n;i++){
    k2=i;
    k1=n-i;
    l=0;
    for (int j=0;j<k-2;j++){
        if(k1>k2){
            l=1;
            break;
        }
        int tem=k1;
        k1=k2-k1;
        k2=tem;
    }
    if(l==0) c++;

}
cout<<c<<endl;
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