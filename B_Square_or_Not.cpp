#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define endl '\n'
void solve() {
    int a,b,n;
    cin>>n;
    string s;
    cin>>s;
    int sq=sqrt(n);
    if((sq*sq)!=n){
        cout<<"No"<<endl;
        return;
    }
    for(int i=0;i<sq;i++){
        for(int j=0;j<sq;j++){
            bool edge= i==0 || i==sq-1 || j==0 || j==sq-1;
            if( edge ^ s[i*sq+j]=='1'){
                cout<<"No"<<endl;
                return;
            }
        }
    }
    cout<<"Yes"<<endl;
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