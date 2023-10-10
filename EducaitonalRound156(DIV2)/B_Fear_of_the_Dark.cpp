#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define endl '\n'
void solve()
{
    // ld px, py, ax, ay, bx, by, dap, dbp, dao, dbo;
    // cin >> px >> py;
    // cin >> ax >> ay;
    // cin >> bx >> by;
    // dap = pow((ax - px), 2) + pow((ay - py), 2);
    // dao = pow(ax, 2) + pow(ay, 2);
    // dbp = pow((bx - px), 2) + pow((by - py), 2);
    // dbo = pow(bx, 2) + pow(by, 2);
    // if ((dap <= dbp && dao <= dbo))
    // {
    //     int t = max(dap, dao);
    //     cout << fixed << setprecision(10) << sqrt(t) << endl;
    // }
    // else if ((dap >= dbp && dao >= dbo))
    // {
    //     int t = max(dbp, dbo);
    //     cout << fixed << setprecision(10) << sqrt(t) << endl;
    // }
    // else
    // {
    //     if (dbp < dap)
    //     {
    //         if (dbp >= dbo)
    //         {
    //             cout << fixed << setprecision(10) << sqrt(dbp) << endl;
    //         }
    //         else
    //         {
    //             int temp = pow((ax - bx), 2) + pow((ay - by), 2);
    //             if(sqrt(temp)/2<sqrt(dbp))
    //             cout << fixed << setprecision(10) << sqrt(dbp)<< endl;
    //             else
    //             cout << fixed << setprecision(10) << sqrt(temp) / 2 << endl;
    //         }
    //     }
    //     else
    //     {
    //         if (dap >= dao)
    //         {
    //             cout << fixed << setprecision(10) << sqrt(dap) << endl;
    //         }
    //         else
    //         {
    //             int temp = pow((ax - bx), 2) + pow((ay - by), 2);
    //             if (sqrt(temp) / 2 < sqrt(dap))
    //             cout << fixed << setprecision(10) << sqrt(dap) << endl;
    //             else
    //             cout << fixed << setprecision(10) << sqrt(temp) / 2 << endl;
    //         }
    //     }
    // }
    ll px, py, ax, ay, bx, by;
    cin>>px>>py>> ax>> ay>> bx>> by;
    double dab = (ax - bx) * (ax - bx) + (ay - by) * (ay - by);
    double d0a = (ax - 0) * (ax - 0) + (ay - 0) * (ay - 0);
    double d0b = (0 - bx) * (0 - bx) + (0 - by) * (0 - by);
    double dpa = (ax - px) * (ax - px) + (ay - py) * (ay - py);
    double dpb = (bx - px) * (bx - px) + (by - py) * (by - py);
    double res = 1e17;
    // both in a
    res = min(res, max(d0a, dpa));
    // both in b
    res = min(res, max(d0b, dpb));
    // 0 in a, p in b
    res = min(res, max(dab * 0.25, max(d0a, dpb)));
    // 0 in b, p in a
    res = min(res, max(dab * 0.25, max(d0b, dpa)));
    cout << fixed << setprecision(10) << sqrt(res)<< endl;
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