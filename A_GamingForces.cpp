#include<bits/stdc++.h>
#define ll long long
using namespace std;
int main()
{
    ll t;
    cin >> t;
    while(t--)
    {
        int n, c=0,a[100];
        cin>>n;
        for (int i = 0; i < n; i++)
        {
            cin>>a[i];
            if(a[i]==1) c++;
        }
        cout<<(n-c/2)<<endl;

        
    }
    return 0;
}