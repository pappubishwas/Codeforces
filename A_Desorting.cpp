#include <bits/stdc++.h>
#include <cstring>
using namespace std;
#define ll long long
#define ld long double
#define endl '\n'


void solve()
{
int n,k=0,diff,c=0,min=1000000000;
cin>>n;
int a[n];
for(int i=0;i<n;i++){
    cin>>a[i];
}
for (int i = 0;i < n-1;i++){
diff=a[i+1]-a[i];
if(diff<0){
    k=-1;
    break;
}
if(min>diff) min=diff;

}
if(k==-1) cout<<0<<endl;
else cout<<(min/2)+1<<endl;

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