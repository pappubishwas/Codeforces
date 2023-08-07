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
set<int> s;
std::set<int>::iterator it;
for ( i = 0; i < n; i++)
{
    int p;
    cin>>p;
    v.push_back(p);
}
sort(v.begin(),v.end());
for ( i = 0; i < n-1; i++)
{
    if(v[i+1]-v[i]<=k) c++;
    else{
        s.insert(n-c);
        c=1;
    }
}
s.insert(n-c);
if(s.size()==0) cout<<0<<endl;
else{
    it=s.begin();
    cout<<*it<<endl;
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