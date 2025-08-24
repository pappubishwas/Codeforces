#include <bits/stdc++.h>
using namespace std;

#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

typedef long long ll;
const int MOD = 1e9+7;

#define SUVRAT ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

const int N = 30;
ll p[N];

ll fun(ll x)
{
    return p[x+1] + x*p[x-1];
}

int main()
{
    SUVRAT

    p[0] = 1;
    for(ll i = 1; i < N; i++) p[i] = p[i-1] * 3;


    ll t;
    cin >> t;
    while(t--)
    {
        ll n, k;
        cin >> n >> k;

        ll ans = 0;
        ll x = 0;

        ll bit[N];
        for(ll i = 0; i < N; i++) bit[i] = 0;

        while(n > 0)
        {
            ans += fun(x) * (n % 3);
            bit[x] = (n % 3);
            k -= (n % 3);

            n /= 3;
            x++;
        }

        if(k < 0) 
        {
            cout << -1 << endl;
            continue;
        }

        ll reduction = 0;
        for(ll i = N-1 ; i >= 1 ; i--)
        {
            if(k > 1 && bit[i])
            {
                ll times = min(k/2, bit[i]);

                k -= times * 2;
                bit[i] -= times;

                bit[i-1] += 3*times;

                reduction += times * p[i-1];
            }
        }



        cout << ans - reduction << endl;

    }

    return 0;
}