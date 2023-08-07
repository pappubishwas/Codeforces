#include <bits/stdc++.h>
#include <cstring>
using namespace std;
#define ll long long
#define ld long double
#define endl '\n'
void solve()
{
vector<int> ans,v;
int n,i,j,c=0,k;
cin>>n;
for(i=0;i<n;i++){
    cin>>k;
    ans.push_back(k);
    v.push_back(k);
}
sort(v.begin(),v.end());

for(i=0;i<n;i++){
    if((ans[i]%2==0 && v[i]%2==0) || (ans[i]%2!=0 && v[i]%2!=0)) continue;
    else{
        c=1;
        break;
    }
}
if(c==0) cout<<"YES"<<endl;
else cout<<"NO"<<endl;
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