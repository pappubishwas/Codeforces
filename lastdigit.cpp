#include <bits/stdc++.h>
#define ll long long
#define ld long double
using namespace std;

int main()
{
    ll n, i, ram=0, raj=0, j = 0, m,k,r;
    cin >>n>>m;

    r=n%10;
    for ( i = 1; i < m; i++)
    {
        k=r*n;
        r=k%10;

    }
    
    cout<<r<<endl;
    
    return 0;
}