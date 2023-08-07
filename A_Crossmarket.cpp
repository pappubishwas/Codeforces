#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define endl '\n'
void solve()
{
int row,col;
cin>>row>>col;
if(row>col)
cout<<(row+2*col-2)<<endl;
else if (row==1 && col==1)
cout<<0<<endl;
else
cout<<(2*row + col -2)<<endl;
    
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