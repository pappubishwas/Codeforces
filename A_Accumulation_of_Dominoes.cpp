#include <bits/stdc++.h>
#include<iostream>
#include<algorithm>
#include <numeric>
using namespace std;
#define ll long long
#define ld long double
#define endl '\n'
void solve()
{
ll row,col;
cin>>row>>col;
if(row==1)
cout<<col-1<<endl;
else if(col==1)
cout<<row-1<<endl;
else
cout<<(row*(col-1))<<endl;

}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
        solve();
}