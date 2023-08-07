#include <bits/stdc++.h>
#define ll long long
#define ld long double
using namespace std;
int main()
{
    ll n, i, ram=0, raj=0, j = 0, m,k,r;
    cin >>n>>m;
    ll a[m][2];
    vector<ll>v1,v2;
    for ( i = 0; i < m; i++)
    {
     cin>>a[i][0]>>a[i][1];   
    }
    for ( i = 0; i < m; i++)
    {
        for ( j = 0; j < v1.size(); j++)
        {
            if(a[i][0]==v1[j]){
                ram=1;
                break;
            }
            if(a[i][0]==v1[j]){
                raj=1;
                break;
            }
            
        }
        
    }
    
    return 0;
}