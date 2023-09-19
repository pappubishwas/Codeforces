// #include <iostream>
// #include <string>

// int main() {
//     std::string str1 = "apple";
//     std::string str2 = "banana";

//     if (str1 > str2) {
//         std::cout << str1 << " is lexicographically greater than " << str2 << std::endl;
//     } else if (str1 < str2) {
//         std::cout << str2 << " is lexicographically greater than " << str1 << std::endl;
//     } else {
//         std::cout << str1 << " and " << str2 << " are lexicographically equal" << std::endl;
//     }

//     return 0;
// }

#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define endl '\n'

void solve()
{
    ll n, k;
    cin >> n >> k;
    string s, st1 = "", st2 = "";
    cin >> s;
    ll i = 0;
    while (i < n)
    {
        if (i % 2 == 0)
            st1 += s[i];
        else
            st2 += s[i];
        i++;
    }
    sort(st1.begin(), st1.end());
    sort(st2.begin(), st2.end());
    s = "";
    i = 0;
    while (i < st1.length() && i < st2.length())
    {
        s += st1[i];
        s += st2[i];
        i++;
    }
    if (i < st1.length())
    {
        s += st1[i];
    }
    if (i < st2.length())
    {
        s += st2[i];
    }
    ll start = 0, c = 0;
    while ((start + k) <= n)
    {
        if ((start + k) <= n)
        {
            std::string temp, subStr = s.substr(start, k);
            temp = subStr;
            std::reverse(subStr.begin(), subStr.end());
            // cout<<subStr<<" ";
            if (subStr < temp)
            {
                // cout<<subStr<<" ";

                c = 1;
                string pre, next;
                pre = s.substr(0, start);
                next = s.substr((start + k), (n - start - k));
                s = pre + subStr + next;
                // cout<<s<<" ";
            }
        }

        if ((start + k) == n && c == 1)
        {
            c = 0;
            start = -1;
        }
        start++;
    }

    cout << s << endl;
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

