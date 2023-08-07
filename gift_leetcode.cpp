#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define endl '\n'
void solve()
{
    int gift[1000],k,n,i;
    cin>>n;
    for ( i = 0; i < n; i++)
    {
        cin>>gift[i];
    }
    cin>>k;
    for ( i = 0; i <k; i++)
    {
        sort(gift,gift+n);
        int p=sqrt(gift[n-1]);
        gift[n-1]=p;
    }
    int sum=0;
    for ( i = 0; i < n; i++)
    {
        sum=sum+gift[i];
    }
    cout<<sum<<endl;
    

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