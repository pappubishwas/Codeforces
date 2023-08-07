#include <bits/stdc++.h>
#include <cstring>
using namespace std;
#define ll long long
#define ld long double
#define endl '\n'
void solve()
{
ll n,i,j,k;
cin >>n;
ll m[n];
string s[n];
for (i=0;i<n;i++){
    cin >>m[i];
    cin>>s[i];
}
std::set<ll> st1,st2,st3;
for(i=0;i<n;i++){
    if(s[i][0]=='1' && s[i][1]=='1') st1.insert(m[i]);
    else if(s[i][0]=='1' && s[i][1]=='0') st2.insert(m[i]);
    else if(s[i][0]=='0' && s[i][1]=='1') st3.insert(m[i]);
}
auto p=st1.begin();
auto q=st2.begin();
auto r=st3.begin();
if(st2.size()==0 || st3.size()==0){
    if(st1.size()==0) cout<<-1<<endl;
    else cout<<*p<<endl;
}
else{
    if((st1.size()!=0 && *p<=(*q+*r))) cout<<*p<<endl;
    else cout<<(*q+*r)<<endl;
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