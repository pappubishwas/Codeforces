#include <bits/stdc++.h>
#include <iostream>
using namespace std;

void solve()
{
string s;
cin>>s;
sort(s.begin(),s.end());
if(s[0]==s[3]) cout<<-1<<endl;
else if(s[0]==s[2] || s[1]==s[3]) cout<<6<<endl;
else cout<<4<<endl;

}

int main()
{
    long long tc;
    cin >> tc;
    while (tc--)
    {
        solve();
    }
    return 0;
}


