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
        ll n, k, ans = 0;
        cin >> n >> k;
        string s;
        cin >> s;
        vector<int> small(26, 0);
        vector<int> capital(26, 0);
        for (size_t i = 0; i < n; i++)
        {
            if (s[i]>='a' && s[i] <= 'z')
                small[s[i] - 'a']++;
            else
                capital[s[i] - 'A']++;
        }
        for (size_t i = 0; i < 26; i++)
        {
            ans += min(small[i], capital[i]);
            if (k > 0 && abs(small[i] - capital[i]) > 1)
            {
                int t = abs(small[i] - capital[i]) / 2;
                if (k > t)
                    ans += t;
                else
                    ans += k;
                k -= t;
            }
        }
        cout << ans << endl;
    }
    return 0;
}
