#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define endl '\n'
void solve()
{
    string s;
    cin >> s;
    char ch[2000];
    stack<int> st1;
    stack<int> st2;
    for (size_t i = 0; i < s.size(); i++)
    {
        if (s[i] == 'b')
        {
            if (!st1.empty())
            {
                int t = st1.top();
                st1.pop();
                s[t] = '0';
            }
            s[i] = '0';
        }
        else if (s[i] == 'B')
        {
            if (!st2.empty())
            {
                int t = st2.top();
                st2.pop();
                s[t] = '0';
            }
            s[i] = '0';
        }
        else
        {
            if (s[i] >= 'a' && s[i] <= 'z')
            {
                st1.push(i);
            }
            else if (s[i] >= 'A' && s[i] <= 'Z')
            {
                st2.push(i);
            }
        }
    }
    for (size_t i = 0; i < s.size(); i++)
    {
        if (s[i] != '0')
            cout << s[i];
    }
    cout << endl;
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