#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define endl '\n'
void solve()
{
ll n,q;

//scanf("%u%u",&n,&q);
cin>>n;
cin>>q;
ll  a[n],p[10000],t[100000],sum=0,c=0,i,j;
for(i=0;i<n;i++) cin>>a[i];

for(j=0;j<q;j++) cin>>p[j]>>t[j];

for(i=0;i<n;i++) {
    sum+=a[i];
    if(a[i]%2==0) c++;
}
for(i=0;i<q;i++){
    if(p[i]==0){
        sum=sum+(c*t[i]);
        cout<<sum<<endl;
    }else{
        sum=sum+((n-c)*t[i]);
        cout<<sum<<endl;
    }
}
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}






// #include<bits/stdc++.h>
// #define ll long long
// using namespace std;
// int main()
// {
//     ll t;
//     cin >> t;
//     while(t--)
//     {
//         ll n , q;
//         cin >> n >> q;
//         ll i, j;
//         ll odd = 0, even = 0, sum = 0;
//         ll a[n];
//         for(ll i = 0; i < n; i++)
//         {
//             cin >> a[i];
//             if(a[i] % 2 == 1)
//                 odd++;
//             else
//                 even++;
//             sum += a[i];
//         }
//         while(q--)
//         {
//             cin >> i >> j;
//             i ? sum += (odd * j) : sum += (even * j);
//             cout << sum << endl;
//             if(j % 2 == 1)
//             {
//                 if(!i)
//                 {odd = n, even = 0;}
//                 else {odd = 0, even = n;}
//             }
//         }
//     }
//     return 0;
// }