
#include <bits/stdc++.h>
#include<cstring>
using namespace std;
#define ll long long
#define ld long double
#define endl '\n'
void solve()
{
ll n,k,count=0,j=0;
cin>>n>>k;
string st;
cin>>st;
int i=0;
while(i<n){
    j=0;
    if(st[i]=='B'){
        count+=1;
        for(j=0;j<k && i<n;j++){
            st[i]='W';
            i++;
        }
        i--;
    }
    i++;
}
cout<<count<<endl;
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