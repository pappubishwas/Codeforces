#include <bits/stdc++.h>

using namespace std;

#define _test     \
    int _TEST;    \
    cin >> _TEST; \
    while (_TEST--)

int main()
{
    _test
    {
        int n;
        string s;
        cin >> n >> s;

        vector<int> v(n);

        string temp = s, t;
        reverse(temp.begin(), temp.end());
        char ch = temp[0];
        int idx = 0;
        for (int i = 1; i < n; i++)
        {
            if (temp[i] >= ch)
            {
                t.push_back(ch);
                ch = temp[i];
                v[n - idx - 1] = 1;
                idx = i;
            }
        }
        t.push_back(ch);
        v[n - idx - 1] = 1;
        reverse(t.begin(), t.end());

        int ans = 0;
        for (int i = 25; i >= 0; i--)
        {
            if (count(t.begin(), t.end(), i + 'a') > 0)
            {
                ans -= count(t.begin(), t.end(), i + 'a');
                break;
            }
        }

        for (int i = 0; i < n; i++)
        {
            if (v[i])
            {
                ans++;
                s[i] = t.back();
                t.pop_back();
            }
        }

        if (is_sorted(s.begin(), s.end()))
            cout << ans << "\n";
        else
            cout << -1 << "\n";
    }
}