#include <bits/stdc++.h>
#include <cstring>
using namespace std;
#define ll long long
#define ld long double
#define endl '\n'
void solve()
{
ll n,a,b;
cin >> n;
cin >> a;
cin >> b;
if(n==1 && a==b){
    cout<<1<<endl;
    cout<<a<<":"<<b<<endl;
}else{
    if(a+b>=n){
        cout<<0<<endl;
        for (int i = 0; i < n; i++)
        {
            cout<<i<<":"<<i+1<<endl;
        }
        
    }
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