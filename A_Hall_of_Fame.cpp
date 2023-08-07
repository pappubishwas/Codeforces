#include <bits/stdc++.h>
#include<cstring>
using namespace std;
#define ll long long
#define ld long double
#define endl '\n'
void solve()
{
    ll t,r=0,l=0,k=0;
        int i,n;
        string p;
        cin>>n;
        cin>>p;
        for ( i = 0; i < n; i++)
        {
            if(p[i]=='R') r=1;
            else if(r==1 && p[i]=='L'){
                l=1;
                break;
            }
            else if(p[i]=='L' && i!=n && p[i+1]=='R'){
                k=i+1;
                break;
            }
        }
        if(r==1 && l==1)cout<<0<<endl;
        else if(k!=0)cout<<k<<endl;
        else cout<<-1<<endl;

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

// #include <bits/stdc++.h>
// #define ll long long
// using namespace std;
// int main()
// {
//     ll t,r=0,l=0,k=0;
//     cin >> t;
//     while (t--)
//     {
//         int i,n;
//         string p;
//         cin>>n;
//         cin>>p;
//         for ( i = 0; i < n; i++)
//         {
//             if(p[i]=='R') r=1;
//             else if(r==1 && p[i]=='L'){
//                 l=1;
//                 break;
//             }
//             else if(p[i]=='L' && i!=n && p[i+1]=='R'){
//                 k=i+1;
//                 break;
//             }
//         }
//         if(r==1 && l==1)cout<<0<<endl;
//         else if(k!=0)cout<<k<<endl;
//         else cout<<-1<<endl;
//     }
//     return 0;
// }