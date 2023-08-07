#include<bits/stdc++.h>
#define ll long long
using namespace std;
int main()
{
    ll t;
    cin >> t;
    while(t--)
    {
        int w,d,h,a,b,f,g,p[4];
        cin>>w>>d>>h;
        cin>>a>>b>>f>>g;
        p[0]=h+b+g+abs(a-f);
        p[1]=a+h+f+abs(b-g);
        p[2]=2*w-a-f+h+abs(b-g);
        p[3]=2*d-b-g+h+abs(a-f);
        sort(p,p+4);
        cout<<p[0]<<endl;

        
    }
    return 0;
}