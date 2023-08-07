#include <bits/stdc++.h>
#include<cstring>
using namespace std;
#define ll long long
#define ld long double
#define endl '\n'
void solve()
{
ll n;
cin>>n;
if(n==3) cout<<"NO"<<endl;
else if(n%2==0){
    cout<<"YES"<<endl;
    for (int i = 0; i < n; i++)
    {
        if(i%2==0)cout<<1<<" ";
        else cout<<-1<<" ";
    }
    cout<<endl;
}else{
    cout<<"YES"<<endl;
    for (int i = 0; i < n; i++)
    {
        if(i%2==0)cout<<(n/2-1)<<" ";
        else cout<<-(n/2)<<" ";
    }
    cout<<endl;    
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