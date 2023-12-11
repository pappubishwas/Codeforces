#include <bits/stdc++.h>
using namespace std;
#define gcd __gcd
#define ll long long
#define ld long double
#define endl '\n'
#define vvl vector<vll>
#define pll pair<ll, ll>
const int mod = 1e9 + 7;

int main()
{
    int T;
    cin >> T;

    while (T--)
    {
        ll n, sum = 0;
        cin >> n;

        vector<ll> ans(n);
        for (size_t i = 0; i < n; i++)
        {
            cin >> ans[i];
            sum += ans[i];
        }

        vector<ll> temp = ans;
        sort(ans.begin(), ans.end());
        reverse(ans.begin(), ans.end());

        map<ll, int> mp;
        for (size_t i = 0; i < n; i++)
        {

            if (i > 0 && sum >= ans[i - 1])
                mp[ans[i]] = mp[ans[i - 1]];
            else
                mp[ans[i]] = n - i - 1;
            sum -= ans[i];
        }

        for (size_t i = 0; i < n; i++)
        {
            cout << mp[temp[i]] << " ";
        }
        cout << endl;
    }
    return 0;
}
