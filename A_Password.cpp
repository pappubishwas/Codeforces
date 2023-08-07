#include<bits/stdc++.h>
#define ll long long
using namespace std;
int fact(int n){

     return (n==0) || (n==1) ? 1 : n* fact(n-1);
}
int main()
{
    ll t;
    cin >> t;
    while(t--)
    {
        int n,a[8],p;
        cin>>n;
        for(int i=0;i<n;i++) cin>>a[i];
        p=10-n;
        cout<<3*fact(p)/fact(p-2)<<endl;
    }
    return 0;
}