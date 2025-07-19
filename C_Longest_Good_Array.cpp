#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define endl '\n'
void solve() {
    int a,b,n,l,r;
    cin>>l>>r;
    int res=0,d=1;
    while(l<=r){
        res++;
        l+=d;
        d++;
    }
    cout<<res<<endl;
    
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