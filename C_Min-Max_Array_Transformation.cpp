#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define endl '\n'
void solve()
{
    int n,i,j=1,k=0;
    cin>>n;
    int a[n],b[n],d1[n],d2[n];
    for ( i = 0; i <n; i++)
        cin>>a[i];
    for ( i = 0; i <n; i++)
        cin>>b[i];
    for ( i = 0; i < n; i++)
    {
        j--;
        while(j<n)
        {
            if((b[i] - a[j])>=0 && k<n){
                d1[k]= (b[i]-a[j]);
                k++;
            }else
            break;
            j++;
        }
        if(k==n) 
            break;
        
    }
    // for ( i = 0; i < n; i++)
    // {

    //     j++;
    //     while(j>=0)
    //     {
    //         if((b[i] - a[j])>=0 && k<n){
    //             d2[k]= (b[i]-a[j]);
    //             k++;
    //         }else
    //         break;
    //         j--;
    //     }
    //     if(k==n) 
    //         break;
        
    // }
    for ( i = 0; i < n; i++)
    {
    cout<<" "<<d1[i]<<" ";   
    }
    // for ( i = 0; i < n; i++)
    // {
    // cout<<" "<<d2[i]<<" ";   
    // }
    
    

    
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