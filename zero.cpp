#include <bits/stdc++.h>
#define ll long long
#define ld long double
using namespace std;
ll remainder(ll x){
    ll r=0;
    while (x>0)
    {
        if(x%10>r)r=x%10;
        x=x/10;
    }
    return r;
}
int main()
{
    ll n, i, ram=0, raj=0, j = 0, m,k,r;
    cin >>n;

    while (n>0)
    {
        k=remainder(n);
        n=n-k;
        j++;
    }
    
    
    cout<<j<<endl;
    
    return 0;
}