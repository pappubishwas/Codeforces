#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define endl '\n'
void solve()
{
string p;
cin>>p;
int i,len;
len=p.length();
if(len==3){
    cout<<p[0]<<" "<<p[1]<<" "<<p[2]<<endl;
}else {
    if(p[0]=='b'){
            cout<<p[0]<<" "<<p[1]<<" ";
            for ( i = 2; i < len; i++)
            {
                cout<<p[i];
            }
            cout<<endl;
    }else{
            for ( i = 0; i < len-2; i++)
            {
                cout<<p[i];
            }
            cout<<" "<<p[i]<<" "<<p[i+1]<<endl;
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