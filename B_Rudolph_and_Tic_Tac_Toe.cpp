#include <bits/stdc++.h>
#define ll long long
using namespace std;
int main()
{
    ll tp;
    cin >> tp;
    while (tp--)
    {
        char ch[3][3];
        set<char> s[8];
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                cin >> ch[i][j];
                s[i].insert(ch[i][j]);
            }
        }
        for (int j = 0; j < 3; j++)
        {

            s[j + 3].insert(ch[0][j]);
            s[j + 3].insert(ch[1][j]);
            s[j + 3].insert(ch[2][j]);
        }
        s[6].insert(ch[0][0]);
        s[6].insert(ch[1][1]);
        s[6].insert(ch[2][2]);
        s[7].insert(ch[0][2]);
        s[7].insert(ch[1][1]);
        s[7].insert(ch[2][0]);
        int c = 1;
        for (int i = 0; i < 8; i++)
        {
            if (s[i].size() == 1)
            {
                auto it = s[i].begin();
                // if(*it=='.') cout<<"DRAW"<<endl;
                if (*it != '.')
                {
                    cout << *it << endl;
                    c = 0;
                    break;
                }
            }
        }
        if (c == 1)
            cout << "DRAW" << endl;
    }
    return 0;
}
