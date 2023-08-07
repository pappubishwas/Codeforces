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
    std::string s,p;
    unsigned long d ,d1,d2=0,n=0;
    cin >> d;
    cin>>s;
for ( int i = 0; i < d-1; i++)
 {
    if(s[i+1]=='1') {
        d2++;
n++;
break;
    }
    n++;
}

if(d2<1)cout<<d<<endl;
else
cout <<n<<endl;
 
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