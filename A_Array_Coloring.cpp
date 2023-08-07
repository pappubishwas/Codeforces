#include <bits/stdc++.h>
#include <cstring>
using namespace std;
#define ll long long
#define ld long double
#define endl '\n'
void solve()
{
    int n,odd=0;
    cin >> n;
    int a[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
        if(a[i]%2==1) odd++;
    }
    if(odd%2==0) cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
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