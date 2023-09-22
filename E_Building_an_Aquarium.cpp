
#include <bits/stdc++.h>
#include<cstring>
using namespace std;
#define ll long long
#define ld long double
#define endl '\n'
void solve() {
    ll n, k, p, i = 0;
    cin >> n >> k;
    vector<ll> v;
    for (i = 0; i < n; i++) {
        cin >> p;
        v.push_back(p);
    }
    ll l = 1, h = k + *max_element (v.begin(), v.end()), ans = 1,mid;
    while (l <= h) {
        mid = (l + h) / 2;
        ll totalSum = 0;
        for (i = 0; i < n; i++) {
            if (mid > v[i])
                totalSum += (mid-v[i]);
        }
              if (totalSum == k) {
            ans=mid;
            break;
        } else if (totalSum < k){
            if(ans<mid)
            ans=mid;
            l = mid+1;
        }
        else
            h = mid-1;
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