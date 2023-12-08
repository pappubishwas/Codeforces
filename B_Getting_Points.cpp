#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define endl '\n'
void solve()
{
    ll n, p, l, k, sum, task, ans;
    cin >> n >> p >> l >> k;
    if (n % 7 == 0)
        task = n / 7;
    else
        task = n / 7 + 1;
    int left = 1, right = n;
    while (left <= right)
    {
        int mid = (left + right) / 2;
        sum = (mid * l);
        if (2 * mid <= task)
            sum += (mid * 2 * k);
        else
            sum += (task * k);
        if (sum == p)
        {
            ans = n - mid;
            break;
        }
        else if (sum > p)
        {
            ans = n - mid;
            right = mid - 1;
        }
        else
            left = mid + 1;
    }
    cout << ans << endl;
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