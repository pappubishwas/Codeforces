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
long long int n,i,j,k=0;
long long int l,g;
long long int a[n];
cin>>n;

for (i = 1; i <= n; i++)
{
    for ( j = 1; j <= n; j++)
    {
        l=std::__detail::__lcm(i,j);
        g=__gcd(i,j);
        double p=(double)(l)/(double)(g);
        // cout<<p;
        if(p<=3)
            k++;
    
    } 
    
}
printf("%lli\n",k);

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