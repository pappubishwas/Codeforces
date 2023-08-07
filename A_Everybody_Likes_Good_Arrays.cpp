// #include <bits/stdc++.h>
// using namespace std;
// #define ll long long
// #define ld long double
// #define endl '\n'
// int findParity(ll x)
// {
//     ll y = x ^ (x >> 1);
//     y = y ^ (y >> 2);
//     y = y ^ (y >> 4);
//     y = y ^ (y >> 8);
//     y = y ^ (y >> 16);

//     // Rightmost bit of y holds the parity value
//     // if (y&1) is 1 then parity is odd else even
//     if (y & 1)
//         return 1;
//     return 0;
// }
// void solve()
// {
//     ll n, m, c, i, j = 0;
//     vector<ll> v;
//     cin >> n;
//     for (i = 0; i < n; i++)
//     {
//         cin >> m;
//         v.push_back(m);
//     }
//     vector<ll>::iterator iter = v.begin();
//         // for (int i = 0; i < v.size(); i++)
//         // cout << v[i] << " ";
//     if (n == 1)
//         cout << 0 << endl;
//     else
//     {
//         for (i = 0; i < n - 1; i++)
//         {
//             if (findParity(v[i]) == findParity(v[i + 1]))
//             {
//                 c = (*iter) *( *(iter+1));
//                 v.erase(v.begin() + (i + 1));
//                 v.erase(v.begin() + i);
//                 v.insert(v.begin() + i, c);
//                 i--;
//                 n--;
//                 j++;
//                 iter--;
//             }
//             iter++;
//         }
//         cout << j << endl;
//     }
//         // for (int i = 0; i < v.size(); i++)
//         // cout << v[i] << " ";
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

#include <stdio.h>
int main()
{
    int t;
    for (scanf("%d", &t); t--;)
    {
        int n, x = -1, y, cnt = 0;
        for (scanf("%d", &n); n--; x = y)
            scanf("%d", &y), y &= 1, cnt += (x == y);
        printf("%d\n", cnt);
    }
}