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
    int pap[n];
    for(int i=0;i<n;i++){
        cin>>pap[i];
    }
    bool flag=true;
    for(int i=0;i<n;i++){
        int v=pap[i]+1;
        for(int j=0;j<n;j++){
            if(v==pap[j]){
                int d=abs(i-j);
                if(d%2==0) flag=false;
            }
        }
    }
    if(flag) cout<<"YES"<<endl;
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