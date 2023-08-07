#include <bits/stdc++.h>
#include <cstring>
using namespace std;
#define ll long long
#define ld long double
#define endl '\n'
void solve()
{
    ll n, alice = 1, blackalice = 0, whitealice = 1, blackbob = 0, whitebob = 0, bob = 0, i = 0, sum = 0, k = 0, t = 2;
    cin >> n;
    while ((alice + bob < n))
    {
        if (i % 2 == 0)
        {
            bob += t + t + 1;
            whitebob += (t);
            blackbob += (t + 1);
            if (alice + bob > n)
            {
                bob = bob - t - t - 1;
                whitebob-=t;
                blackbob-=(t+1);
                sum = n - bob - alice;
                if (sum % 2 == 0)
                {
                    whitebob += (sum / 2);
                    blackbob += (sum / 2);
                }
                else
                {
                    whitebob += (sum / 2);
                    blackbob += (sum / 2+1);
                }
                bob = n - alice;
                break;
            }
            t = t + 2;
        }
        else
        {
            alice += t + t + 1;
            whitealice += (t + 1);
            blackalice += t;
            if (alice + bob > n)
            {
                alice = alice - t - t - 1;
                whitealice-=(t+1);
                blackalice-=t;
                sum = n - bob - alice;
                if (sum % 2 == 0)
                {
                    whitealice += (sum / 2);
                    blackalice += (sum / 2);
                }
                else
                {
                    whitealice += (sum / 2 + 1);
                    blackalice += (sum / 2);
                }
                alice = n - bob;
                break;
            }
            t = t + 2;
        }
        i++;
    }
    cout << whitealice << " " << blackalice <<" "<<whitebob<<" "<<blackbob<<" "<< endl;
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