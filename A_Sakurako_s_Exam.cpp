#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define endl '\n'
void solve() {
    int a,b;
    cin>>a>>b;
    b=(b%2)==1?2:0;
    if((a+b)%2==1)
    cout<<"NO"<<endl;
    else{
        if(a<2 && b>0) cout<<"NO"<<endl;
        else
            cout<<"YES"<<endl;
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