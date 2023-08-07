#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define endl '\n'
void solve()
{
int i,k,n,dif,c=1;
cin>>n>>k;
vector<int> v;
vector<int> m;
std::set<int>::iterator it;
for ( i = 0; i < n; i++)
{
    int p;
    cin>>p;
    v.push_back(p);
}

for ( i = 0; i < n-1; i++)
{
   dif=abs(v[i]-v[i+1]);
   m.push_back(dif);
}
sort(m.begin(),m.end());
for ( i = 0; i < k-1; i++)
{
    m.pop_back();
}
if(m.size()==0) cout<<0<<endl;
else
cout<<accumulate(m.begin(),m.end(),0)<<endl;


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