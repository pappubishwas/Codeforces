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
        int n,c;
        string a;
        cin>>n;
        cin>>a;
        if(a[0]=='0')c=0;
        else c=1;
        for (int i = 1; i < n; i++)
        {
            if(a[i]=='1' && c==1){
                cout<<'-';
                c=0;
            }else if(a[i]=='1') {
                cout<<'+';
                c=1;
            }
            else cout<<'+';
        }
        cout<<endl;
        
    }
    return 0;
}