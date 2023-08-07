#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define endl '\n'
void solve()
{
int n,a[50],p=0;
cin>>n;
for(int i=0;i<n;i++) cin>>a[i];
string s;
cin>>s;
for(int i=0;i<n;i++){
    for(int j=i+1;j<n;j++){
        if(a[j]==a[i]){
            if(s[j]!=s[i]){
                p=1;
                break;
                
            }
        }
    }
    if(p==1)break;
}
if(p==1) cout<<"NO"<<endl;
else cout<<"YES"<<endl;
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