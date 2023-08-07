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
int i,sum=0,j;
char a[8][8],ch;
for(i=0;i<8;i++){
for (j = 0; j < 8; j++)
{
    cin >>a[i][j];
}
}

for(i=0;i<8;i++){
    j=0;
    if(a[i][j]!='.'){
for ( j = 0; j < 8; j++)
{
    sum=1;
    if(a[i][j]=='B'){
        ch='B';
        break;
    }else if(a[i][j]=='R') ch='R';
    else break;
}
if(j==8 && a[i][7]=='R'){
    break;
}
}
}

if(sum==0)cout<<"B"<<endl;
else if(j==8) cout<<ch<<endl;
else cout<<ch<<endl;

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