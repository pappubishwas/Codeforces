// #include <bits/stdc++.h>
// using namespace std;
// using ll = long long;

// void solve() {
//     ll n;
//     cin >> n;

//     vector<ll> pow3;
//     pow3.push_back(1);
//     while (pow3.back() <= n) {
//         pow3.push_back(pow3.back() * 3);
//     }

//     ll ans = 0;
//     while (n > 0) {
     
//         int x = upper_bound(pow3.begin(), pow3.end(), n) - pow3.begin() - 1;
        
//         ans += (pow3[x+1] + x * pow3[x-1]);
//         n -= pow3[x];

//         if (n < 3) {
//             ans += (3 * n);
//             n = 0;
//         }
//     }

//     cout << ans << "\n";
// }

// int main() {
//     ios::sync_with_stdio(false);
//     cin.tie(nullptr);

//     int t;
//     cin >> t;
//     while (t--) {
//         solve();
//     }
//     return 0;
// }



#include <bits/stdc++.h>
using namespace std;

#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

typedef long long ll;
const int MOD = 1e9+7;

#define PAPPU ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

const int N = 30;
ll p[N];

ll fun(ll x)
{
    return p[x+1] + x*p[x-1];
}

int main()
{
    PAPPU

    p[0] = 1;
    for(ll i = 1; i < N; i++) p[i] = p[i-1] * 3;


    ll t;
    cin >> t;
    while(t--)
    {
        ll n;
        cin >> n;

        ll ans = 0;
        ll x = 0;

        while(n > 0)
        {
            ans += fun(x) * (n % 3);
            
            n /= 3;
            x++;
        }

        cout << ans << endl;

    }

    return 0;
}