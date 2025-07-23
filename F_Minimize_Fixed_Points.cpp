#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define endl '\n'

vector<ll> lf(1000001, 1);

void solve()
{
    ll n, k;
    cin >> n;

    vector<ll> a(n);
    for (int i = 0; i < n; i++)
    {
         a[i]=i+1;
    }
    for (int i = n; i >1; i--){
        if(lf[i]==1) continue;
        swap(a[i-1], a[lf[i]-1]);
    }
    for(auto &x : a)
    {
        cout << x << " ";
    }
    cout << endl;

}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    ll t;
    for(int i=4;i<=100007;i++){
        for(int j=2;j<=sqrt(100007);j++){
            if(i%j==0){
                lf[i]=i/j;
                break;
            }
        }
    }
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}