#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define endl '\n'
void solve()
{
    ll a,b;
    cin>>a>>b;
    if(a==b)cout<<0<<endl;
    else if(b>a){
        if(b%2==1){
            if(a%2==0)
            cout<<1<<endl;
            else
            cout<<2<<endl;
        }else{
            if(a%2==0)
            cout<<2<<endl;
            else
            cout<<1<<endl;
        }
    }else{
        if(b%2==1){
            if(a%2==1)cout<<1<<endl;
            else cout<<2<<endl;

        }else{
            if(a%2==1)cout<<2<<endl;
            else cout<<1<<endl;
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