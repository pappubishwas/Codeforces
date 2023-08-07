#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define endl '\n'
void solve()
{
int col,c=0;
cin>>col;
string p1,p2;
cin>>p1;
cin>>p2;
for(int i=0;i<col;i++){
    if((p1[i]=='R' && p2[i]!='R')||(p2[i]=='R' && p1[i]!='R')){
        c++;
        break;
    }
}
if(c==1)
cout<<"NO"<<endl;
else
cout<<"YES"<<endl;
    
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