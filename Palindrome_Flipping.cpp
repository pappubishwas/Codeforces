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
int n,i=0,j,p=0;
string s;
cin >>n;
cin >>s;
if(n%2==1) cout<<"YES"<<endl;
else{
    j=n-1;
    while (i!=j+1)
    {
        if(s[i]!=s[j]) p++;

        i++;j--;
    }
    if(p%2==0) cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
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

