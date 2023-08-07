#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define endl '\n'
void solve()
{
int s ,r,n,i;
cin>>n>>s>>r;
int p[100];
int t;
if(r%(n-1)==0){
    for ( i = 0; i < n-1; i++)
    {
        p[i]=r/(n-1);
    }
    
}else{
    //t=float(r)/(float(n)-1);
    for (i = 0; i < n-2; i++)
    {
        
        p[i]=r/(n-1);
    }
    p[i]=r-(r/(n-1))*(i);
    if(p[i]>(s-r)){
        t=p[i]-(s-r);
        p[i]=s-r;
        for(int j=0;j<t;j++)
        p[j]+=1;
    }
}
for ( i = 0; i < n-1; i++)
{
    cout<<p[i]<<" ";
}
cout<<s-r<<endl;

}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    ll t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}