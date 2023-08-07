#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define endl '\n'
void solve()
{
    int i, k, n, max = 0, c = 1;
    cin >> n;
    int arr[n];
    for (i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    i = n - 1;
    while (i > 0)
    {
        if (arr[i] < arr[i - 1])
        {
            if (max < arr[i - 1])
                max = arr[i - 1];
        }
        i--;
    }
    cout << max << endl;
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