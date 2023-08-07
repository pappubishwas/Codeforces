#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n,m;
        cin >> n ;
        int a[100];
        for (int i = 0; i <n; i++)
        {
            cin>>a[i];
        }
        int ans=0,x=0;
        for (int i = 0; i <n; i++)
        {
            ans+=(a[i]-x)/120;
            x=a[i];
        }
        ans+=(1440-x)/120;
        if(ans>=2)cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
}
