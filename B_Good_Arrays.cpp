#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define endl '\n'
void solve()
{
    long long i, k, n, sum = 0, c = 1;
    cin >> n;
    long long a[n];
    // set<long long> s;

    for (i = 0; i < n; i++)
    {
        cin >> a[i];
        // s.insert(a[i]);
        sum += a[i];
    }
    for (i = 0; i < n; i++)
    {
        if (a[i] == 1)
            sum = sum - 2;
        else
            sum = sum - 1;

        if (sum < 0)
            break;
    }
    // long long size=s.size();
    if (n == 1)
        cout << "NO" << endl;
    // else if(n==size) cout<<"YES"<<endl;
    else
    {
        //    if((sum-size)>=n)
        // cout<<"YES"<<endl;
        // else cout<<"NO"<<endl;
        if (sum < 0)
            cout << "NO" << endl;
        else
            cout << "YES" << endl;
    }
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