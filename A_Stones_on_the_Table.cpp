#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define endl '\n'
void solve()
{ 
    int n,i,c=0;
    cin>>n;
    string p;
    cin>>p;
    for ( i = 0; i < n-1; i++)
    {
        if(p[i]==p[i+1])
            c++;
    }
    cout<<c<<endl;

}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
        solve();
    return 0;
}