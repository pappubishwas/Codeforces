// Recursive call.................

// #include <bits/stdc++.h>
// using namespace std;

// const int mod = 1e9 + 7;
// typedef long long ll;

// int findres(vector<vector<ll>>& a,string s, int curr)
// {
//     ll left = a[curr - 1][0];
//     ll right = a[curr - 1][1];
//     if (left == right)
//         return 0;
//     ll leftval = INT_MAX;
//     ll rightval = INT_MAX;
//     if (left != 0)
//         leftval = findres(a,s, left);
//     if (right != 0)
//         rightval = findres(a,s, right);
//     if (s[curr - 1] == 'U')
//         return 1 + min(leftval, rightval);
//     if (right != 0 && s[curr - 1] == 'L')
//         rightval += 1;
//     if (left != 0 && s[curr - 1] == 'R')
//         leftval += 1;
//     return min(rightval, leftval);
// }

// void solve()
// {
//     ll n;
//     cin >> n;
//     vector<vector<ll>> a(n, vector<ll>(2));
//     ll res = 0, mx = 0, currsum = 0;
//     string s;
//     cin >> s;
//     for (int i = 0; i < n; ++i)
//     {
//         cin >> a[i][0] >> a[i][1];
//     }
//     cout << findres(a,s, 1) << endl;
// }

// int main()
// {
//     ios::sync_with_stdio(0);
//     cin.tie(0);

//     ll T;
//     cin >> T;
//     while (T--)
//     {
//         solve();
//     }

//     return 0;
// }





#include <bits/stdc++.h>
using namespace std;

const int mod = 1e9 + 7;
typedef long long ll;

ll findres(vector<vector<ll>> &a, string s, ll root)
{
    stack<pair<ll, ll>> nodes;
    map<ll, ll> leftValue, rightValue;

    nodes.push({root, 0});
    ll res = INT_MAX;
    while (!nodes.empty())
    {
        ll curr = nodes.top().first;
        ll currdist = nodes.top().second;
        nodes.pop();

        ll left = a[curr - 1][0];
        ll right = a[curr - 1][1];

        if (left == right)
            res = min(res, currdist);

        ll leftVal = INT_MAX;
        ll rightVal = INT_MAX;

        if (left != 0)
        {
            if (s[curr - 1] == 'L')
                nodes.push({left, currdist});
            else
                nodes.push({left, currdist+1});
        }

        if (right != 0)
        {
            if(s[curr-1]=='R')
            nodes.push({right, currdist});
            else
            nodes.push({right, currdist+1});
        }

    }

    return res; 
}

void solve()
{
    ll n;
    cin >> n;
    vector<vector<ll>> a(n, vector<ll>(2));
    ll res = 0, mx = 0, currsum = 0;
    string s;
    cin >> s;
    for (ll i = 0; i < n; ++i)
    {
        cin >> a[i][0] >> a[i][1];
    }
    cout << findres(a, s, 1) << endl;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    ll T;
    cin >> T;
    while (T--)
    {
        solve();
    }

    return 0;
}
