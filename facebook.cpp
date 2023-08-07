// #include<iostream>
// using namespace std;
// int main()
// {
//     int t;
//     cin >> t;
//     while (t--)
//     {
//         int n,k,i;
//         cin>>n>>k;
//         int a[13];
//         for (i = 0; i < n; i++)
//             cin>>a[i];
//         if ((k*2)>=n)
//         {
//             int max=1,j=0;
//             while(max<3 && j<n-1)
//             {
//                 max=1;
//                 i=j+1;
//                 while(i < n)
//                 {
//                     if(a[j]==a[i])
//                         max++;

//                 i++;        
//                 }
//                 j++;
//             }

//             if(max<3)
//                 cout<<"YES"<<endl;
//             else
//                 cout<<"NO"<<endl;
            
//         }else
//         cout<<"NO"<<endl;
        
//     }
    
// }
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define endl '\n'
void solve()
{
        int n,k,i;
        cin>>n>>k;
        int a[n];
        for (i = 0; i < n; i++)
            cin>>a[i];
        if ((k*2)>=n)
        {
            int max=1,j=0;
            while(max<3 && j<n-1)
            {
                max=1;
                i=j+1;
                while(i < n)
                {
                    if(a[j]==a[i])
                        max++;

                i++;        
                }
                j++;
            }

            if(max<3)
                cout<<"YES"<<endl;
            else
                cout<<"NO"<<endl;
            
        }else
        cout<<"NO"<<endl;   
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    ll t;
    int k;
    cin >> t;
    for (k=0;k<t;k++)
    {
        cout<<"case-#"<<k+1<<": ";
        solve();
    }
    return 0;
}