#include<bits/stdc++.h>
#define ll long long
using namespace std;

int main()
{
    ll t;
    cin >> t;
    while(t--)
    {
        ll n;
        cin>>n;
        ll a[n],sum=0,p=0,i;
        string s;
        cin>>s;
        for(i=0;i<n;i++) cin>>a[i];
        
        for ( i = 0; i < n-1; i++)
        {
            if(s[i]=='0' && s[i+1]=='1'){
                p=a[i];
                if(a[i]>a[i+1]){
                    sum+=a[i];
                    s[i+1]='0';
                    p=0;
                }
            }else if(s[i]=='0' && s[i+1]=='0') continue;
            else{
                if(p>a[i]){
                    sum+=p;
                    p=a[i];
                }
                else sum+=a[i];
            }
        }
        if(s[i]=='1'){
            if(p>a[i])sum+=p;
            else
                sum+=a[i];
        }
        cout<<sum<<endl;
    }
    return 0;
}