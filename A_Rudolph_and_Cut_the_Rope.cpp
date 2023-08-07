#include <bits/stdc++.h>
#define ll long long
using namespace std;
int main()
{
    ll tp;
    cin >> tp;
    while(tp--)
    {
        int n,c=0,x,y;
        cin>>n;
        for (int i = 0; i < n; i++)
        {
             cin>>x>>y;
             if(x>y) c++;
        }
        cout<<c<<endl;
    }
    return 0;
}
