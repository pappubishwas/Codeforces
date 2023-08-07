#include <bits/stdc++.h>
#include <cstring>
using namespace std;
#define ll long long
#define ld long double
#define endl '\n'
void solve()
{
    ll n, alice = 1, bob = 0, i = 0, sum = 0, k = 0, t = 2;
    cin >> n;
    while ((alice + bob < n))
    {
        // sum=alice+bob;
        if (i % 2 == 0)
        {
            bob += t + t + 1;
            if (alice + bob > n)
            {
                bob = bob - t - t - 1;
                bob = n - alice;
                break;
            }
            t = t + 2;
        }
        else
        {
            alice += t + t + 1;
            if (alice + bob > n)
            {
                alice = alice - t - t - 1;
                alice = n - bob;
                break;
            }
            t = t + 2;
        }
        i++;
    }
    cout << alice << " " << bob << endl;
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