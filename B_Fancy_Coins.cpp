// #include <bits/stdc++.h>
// using namespace std;
// #define ll long long
// #define ld long double
// #define endl '\n'
// void solve()
// {

//     ll m, k, a1, a2;
//     cin >> m >> k >> a1 >> a2;
//     ll sum1, coin=0,p=a1;

//     while(m>0){
//         if(a2>0 && m>=k){
//             m=m-k;
//             a2--;
//         }else if(a1>0){
//             m=m-a1;
//             a1=0;
//         }else if(m>=k){
//             m=m-k;
//             coin++;
//         }else if((k-m)<=p)
//         {
//             coin++;
//             break;
//         }else{
//             coin=coin+m;
//             break;
//         }
//     }
//     cout<<coin<<endl;
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
#define ll long long
#define ld long double
#define endl '\n'
void solve()
{

    ll m, k, a1, a2;
    cin >> m >> k >> a1 >> a2;
    ll sum1, coin = 0, p = a1;
    sum1 = a2 * k;
    if (sum1 == m || m == a1 || (sum1 + a1) >= m && sum1 <= m)
    {
        cout << 0 << endl;
    }
    else
    {
        if (sum1 < m)
        {
            int coin = 0, t = m - sum1 - a1;
            coin = t / k;
            if (t % k == 0)
                cout << coin << endl;
            else
            {
                if (k - (t % k) <= a1)
                    cout << coin + 1 << endl;
                else
                    cout << (coin + (t % k)) << endl;
            }
        }
        else
        {
            if (m % k == 0 || m % k <= a1)
                cout << 0 << endl;
            else
            {
                int coin = 0, t = m % k;
                coin = t - a1;
                cout << coin << endl;
            }
        }
    }
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