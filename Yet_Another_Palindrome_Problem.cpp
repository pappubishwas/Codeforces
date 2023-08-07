#include <bits/stdc++.h>
#include<iostream>
#include<algorithm>
#include <numeric>
using namespace std;
#define ll long long
#define ld long double
#define endl '\n'

void solve()
{
int n,i,j,k,p=0,a[300000],q=0;
cin>>n;
//ld a[300000];
for ( i = 0; i < n; i++)
{
    cin>>a[i];
}


if(a[0]==a[n-1]){
i=1;j=n-2;
while (i!=j && i!=j+1)
{
    if(a[i]!=a[j]) {
        p++;
        break;
    }
    i++;j--;
}
if(p==0)cout<<0<<endl;
else cout<<-1<<endl;
}else if(a[0]>a[n-1]) cout<<-1<<endl;
else{
i=1;j=n-2;
k=a[n-1]-a[0];
p=k;
while (i!=j && i!=j+1)
{

    if(a[i]<=a[j] && k>=(a[j]-a[i])) {
        k=a[j]-a[i];

        
    }else{
        q++;
        break; 
    } 

    i++;j--;
}
if(q==0) cout<<p<<endl;
else cout<<-1<<endl;

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

