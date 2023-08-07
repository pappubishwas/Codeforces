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
ll i,n,j,k=1,max1=0,max2=0,t,p,q=0,s=0,op=0;
cin >>n;
ll a[n];
vector <ll> v;
for ( i = 0; i < n; i++)
{
    cin >>a[i];
}
for ( i = 0; i < n; i++)
{
    for ( j = 0; j < k; j++)
    {
        max1+=a[j];
    }
    for(t=k;t<n;t++){
        max2+=a[t];
        q++;
        if(max2==max1) {
            max2=0;
            if(q>p) p=q;
            q=0;
        }
        if(max2>max1){
            op=1;
            break;
        } 
    }
    k++;
    if(t==n && q==0 && op==0) {
        v.push_back(p);
}

}
if(p==0) cout<<n<<endl;
else
cout<<*min_element(v.begin(), v.end())<<endl;
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

