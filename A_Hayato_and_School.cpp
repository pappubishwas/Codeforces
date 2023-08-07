#include <bits/stdc++.h>
#include <cstring>
using namespace std;
#define ll long long
#define ld long double
#define endl '\n'
void solve()
{
    ll n, i, j;
    cin >> n;
    vector<ll> v;
    for (i = 0; i < n; i++)
    {
        cin >> j;
        v.push_back(j);
    }
    vector<ll>::iterator iter;
    ll k = 0, a[3],b[2],t=0;
    for (i = 0; i < n; i++)
    {
        if (v[i]% 2 == 1)
        {
            a[k] = i + 1;
            k++;
        }
        if(v[i]%2==0 && t!=2){
            b[t]=i+1;
            t++;
        }
        if (k == 3)
            break;
    }
    if(k==3){
        cout<<"YES"<<endl;
        cout<<a[0]<<" "<<a[1]<<" "<<a[2]<<endl;
    }else if((k>=1 && t==2)){
        cout<<"YES"<<endl;
        cout<<a[0]<<" "<<b[0]<<" "<<b[1]<<endl;
    }else cout<<"NO"<<endl;
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
