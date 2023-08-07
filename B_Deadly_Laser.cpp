// #include <bits/stdc++.h>
// using namespace std;
// #define ll long long
// #define ld long double
// #define endl '\n'
// void solve()
// {
// int n,m,s1,s2,d;
// cin>>n>>m>>s1>>s2>>d;

// if((s1-1)>d && (m-s2)>d)
// cout<<(n+m-2)<<endl;
// else if((s2-1)>d && (n-s1)>d)
// cout<<(n+m-2)<<endl;
// else
// cout<<-1<<endl;   
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
#define ll long long int
#define endl '\n'

int distance(int x1, int y1, int x2, int y2)
{
    return (abs(x1 - x2) + abs(y1 - y2));
}

int solve()
{
    ll a, b, p, q, d;
    cin >> a >> b >> p >> q >> d;
    if (distance(a, b, p, q) <= d)
        return -1;
    bool flag1 = false, flag2 = false;
    if (q - 1 > d && a - p > d)
    {
        flag1 = true;
    }
    if (p - 1 > d && b - q > d)
    {
        flag2 = true;
    }
    if (!flag1 && !flag2)
        return -1;
    return (a + b) - 2;
}
int main()
{
    ll t;
    cin >> t;
    while (t--)
    {
        cout << solve() << endl;
    }
    return 0;
}