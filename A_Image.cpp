// #include <bits/stdc++.h>
// using namespace std;
// #define ll long long
// #define ld long double
// #define endl '\n'
// void solve()
// {
//     char p1,p2,p3,p4;
//     cin >>p1>>p2>>p3>>p4;
//     int j=0,max=1,i,a[4]={p1,p2,p3,p4};
//     while (j<4)
//     {
//         for ( i =j+1 ; i <4; i++)
//         {
//             if(a[j]==a[i])
//                 max++;
//         }
//         j++;
//     }
//     if(max==3 || max==4)
//     cout<<1<<endl;
//     else if(max==2)
//     cout<<2<<endl;
//     else if(max>4)
//     cout<<0<<endl;
//     else
//     cout<<3<<endl;
    
// }
// int main()
// {
//     ios::sync_with_stdio(false);
//     cin.tie(0);
//     cout.tie(0);
//     ll t;
//     cin >> t;
//     while (t--)
//     {
//         solve();
//     }
//     return 0;
// }


#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define endl '\n'

int solve()
{
    unordered_set<char> us;
    for (int i = 0; i < 4; i++)
    {
        char c;
        cin >> c;
        us.insert(c);
    }
    return us.size() - 1;
}
int main()
{
    ll t;
    cin >> t;
    while (t--)
    {
        cout << solve() << endl;
    }
    return 0;
}