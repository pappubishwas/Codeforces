#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define endl '\n'
void solve()
{
int n,i=0,j,c=0,k=0;
cin>>n;
string p;
cin>>p;
j=n-1;
while (i<j)
{
    if(p[i]!=p[j]){
        c+=2;
        i++;
        j--;
    }else{
        break;
    }
}
cout<<n-c<<endl;

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