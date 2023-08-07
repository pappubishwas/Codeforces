#include <bits/stdc++.h>
#include<cstring>
using namespace std;
#define ll long long
#define ld long double
#define endl '\n'
void solve()
{
string p , q="314159265358979323846264338327";
cin>>p;
int c=0,k,i=0;
k=p.length(); //
while (i<k)
{
    if(p[i]!=q[i])break;
    c++;
    i++;
    
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