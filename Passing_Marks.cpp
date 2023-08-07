#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n,m;
        cin >> n >> m;
        int i,j,k,a[n];
        for (i=0;i<n;i++)cin>>a[i];
        sort(a,a+n);
        cout<<a[n-m]-1<<endl;


    }
}
