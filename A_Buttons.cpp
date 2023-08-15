#include <bits/stdc++.h>
#include <cstring>
using namespace std;
#define ll long long
#define ld long double
#define endl '\n'
void solve()
{
ll a,b,c;
cin>>a>>b>>c;
if(a>b)
cout<<"First"<<endl;
else if(a<b)
cout<<"Second"<<endl;
else{
    if(c%2==0)
    cout<<"Second"<<endl;
    else
    cout<<"First"<<endl;
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