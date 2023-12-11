#include <bits/stdc++.h>
using namespace std;
#define gcd __gcd
#define ll long long
#define ld long double
#define endl '\n'
#define vvl vector<vll>
#define pll pair<ll, ll>
const int mod = 1e9 + 7;
ll x2, y2, a, b;
bool can(ll i, ll j)
{
    return ((abs(i - x2) == b and abs(j - y2) == a) or (abs(i - x2) == a and abs(j - y2) == b));
};
int main()
{
    int T;
    cin >> T;
    while (T--)
    {
        cin >> a >> b;
        ll x1, y1;
        cin >> x1 >> y1 >> x2 >> y2;

        set<pll> ans;
        if (can(x1 + a, y1 + b))
            ans.insert({x1 + a, y1 + b});
        if (can(x1 + a, y1 - b))
            ans.insert({x1 + a, y1 - b});
        if (can(x1 - a, y1 + b))
            ans.insert({x1 - a, y1 + b});
        if (can(x1 - a, y1 - b))
            ans.insert({x1 - a, y1 - b});
        if (can(x1 + b, y1 + a))
            ans.insert({x1 + b, y1 + a});
        if (can(x1 + b, y1 - a))
            ans.insert({x1 + b, y1 - a});
        if (can(x1 - b, y1 + a))
            ans.insert({x1 - b, y1 + a});
        if (can(x1 - b, y1 - a))
            ans.insert({x1 - b, y1 - a});
        cout << ans.size() << endl;
    }
    return 0;
}
