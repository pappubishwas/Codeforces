#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve()
{
    ll n, c, k,l,r;
    cin >> l>>r;
    string lt=to_string(l),rt=to_string(r);

    ll mx = INT_MIN, mn = INT_MAX,ans=0;
    for (int i = 0; i < lt.size(); i++)
    {
          if(lt[i]==rt[i]){
             ans+=2;
          }else if(rt[i]-lt[i]>1){
            break;
          }else{
            ans++;
            ll extralt=0;
            for(int j=i+1;j<lt.size();j++){
                if('9'-lt[j]>0){
                    break;
                }else{
                    extralt++;
                    if(rt[j]==lt[j]) extralt++;
                }
            }
            ll extrart=0;
            for(int j=i+1;j<lt.size();j++){
                if(rt[j]-'0'>0){
                    break;
                }else{
                    extrart++;
                    if(rt[j]==lt[j]) extrart++;
                }
            }
            ans+=min(extralt,extrart);
            break;
          }
    }
    cout<<ans<<endl;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}
