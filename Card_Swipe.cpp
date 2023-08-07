#include <bits/stdc++.h>
#include <cstring>
using namespace std;
#define ll long long
#define ld long double
#define endl '\n'
void solve()
{
ll n;
cin>>n;
vector<int> vt;
ll i,j,k,c,size,max=0;
for(i=0;i<n;i++){
cin>>c;
vt.push_back(c);
}
set<int> s;
for (i=0;i<n;i++){
auto it=s.find(vt[i]);
if(it!=s.end()) s.erase(it);
else{
    s.insert(vt[i]);
    c=s.size();
    if(max<c) max=c;
}
}
cout<<max<<endl;

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