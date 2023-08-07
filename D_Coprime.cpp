// #include <bits/stdc++.h>
// #include<iostream>
// #include<algorithm>
// #include <numeric>
// using namespace std;
// #define ll long long
// #define ld long double
// #define endl '\n'
// int gcd(int a , int b)
// {
//    if(b==0) return a;
//    a%=b;
//    return gcd(b,a);
// }
// void solve()
// {
// int i,j,n,p,q;
// cin>>n;
// int a[n],max=0;

// for ( i = 0; i < n; i++)
// {
//     cin>>a[i];
// }
// for ( i = 0; i < n; i++)
// {
//     for ( j = i; j < n; j++)
//     {
//         p=gcd(a[i],a[j]);
//         if (p==1 && max<(i+j+2))
//         {
//             max=i+j+2;
//         }
//     }
    
// }
// if(max==0)cout<<-1<<endl;
// else cout<<max<<endl;


// }
// int main()
// {
//     ios::sync_with_stdio(false);
//     cin.tie(0);
//     cout.tie(0);
//     ll t;
//     cin >> t;
//     while (t--)
//     {
//         solve();
//     }
//     return 0;
// }

#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
typedef long long int ll;
ll gcd(ll a, ll b)
{
    if((a%b)==0)
    {
        return b;
    }else{
        return gcd(b, a%b);
    }
}
int main()
{
    ll t, n, ans, i, j;
    
    cin>>t;
    
    for(;t--;)
    {
        
        ll c[1001];
        
        ans=-1;
        
        for(i=0; i<=1000; i++){
            c[i]=-1;
        }
        
        cin>>n;
        
        for(i=1;i<=n;i++)
        {
            cin>>j;
            c[j]=i;
        }
        
        for(i=1; i<=1000; i++)
        {
            for(j=i; j<=1000; j++)
            {
                if(c[i]>0 && c[j]>0)
                {
                    if(gcd(i, j)==1){
                        ans=max(ans, c[i]+c[j]);
                    }
                }
            }
        }
        
        cout<<ans<<"\n";
    }
}