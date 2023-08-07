#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define endl '\n'
void solve()
{
ll n,m,sum1=0,sum2=0;
cin>>n;
ll a[n],b[n];
for (ll i = 0; i < n; i++)
{
    cin>>a[i];
    sum1+=a[i];
}
for (ll i = 0; i < n; i++)
{
    cin>>b[i];
    sum2+=b[i];
}
sort(b,b+n);
ll sum=sum1+sum2-b[n-1];
cout << sum<<endl;

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
// #include <iostream>
// using namespace std;

// int main()
// {
//     unsigned long int n;
//     cin >> n;
//     for (unsigned long int i = 0; i < n; i++)
//     {
//         unsigned long int rt = 0, r2h = 0, m;
//         cin >> m;
//         unsigned long int row1[m + 1], row2[m + 1];
//         for (unsigned long int j = 0; j < m; j++)
//         {
//             cin >> row1[j];
//             rt += row1[j];
//         }
//         for (unsigned long int j = 0; j < m; j++)
//         {
//             cin >> row2[j];
//             rt += row2[j];
//             if (row2[j] > r2h)
//             {
//                 r2h = row2[j];
//             }
//         }
//         unsigned long int result = rt - r2h;
//         cout << result << endl;
//     }
// }