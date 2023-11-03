#include <bits/stdc++.h>
#include <cstring>
using namespace std;
#define ll long long
#define ld long double
#define endl '\n'
void solve()
{
    int n, p;
    cin >> n;
    vector<int> ans;
    for (int i = 0; i < 2 * n; i++)
    {
        cin >> p;
        ans.push_back(p);
    }
    sort(ans.begin(), ans.end());
    int i = 0, j = 2 * n - 1, min = 0;
    int arr[n][n];
    while (i < j)
    {
        arr[i][0] = ans[j];
        arr[i][1] = ans[i];
        i++;
        j--;
    }
    i = 0;
    while (i < n - 1)
    {
        min += abs(arr[i][0] - arr[i + 1][0]);
        min += abs(arr[i][1] - arr[i + 1][1]);
        i++;
    }

    cout << min << endl;
    i = 0;
    while (i < n)
    {
        cout<<arr[i][0]<<" "<<arr[i][1]<<endl;
        i++;
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