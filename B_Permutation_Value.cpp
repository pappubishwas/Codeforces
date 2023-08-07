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
        int n;
        cin>>n;
        for(int i=1;i<n;i++) cout<<i+1<<" ";
        cout<<1<<endl;
    }
    return 0;
}