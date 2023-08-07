#include <bits/stdc++.h>
#include <cstring>
using namespace std;
#define ll long long
#define ld long double
#define endl '\n'

void solve()
{
    ld n, k = -1,mul=1, c = 1, l = 1, j;
    cin>>n;
    ld a[1000];
    for(ll i=0;i<n;i++){
        cin>>a[i];
        mul=mul*a[i];
    }
    for(ll i=0;i<n;i++){
        c=c*a[i];
        l=mul/c;
        if(c==l){
            k=i+1;
            break;
        }
    }
    cout<<k<<endl;

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
