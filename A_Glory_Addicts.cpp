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
ll n,c=0,*a,*b,i,total=0,j=0,r=0;
cin>>n;
a=(ll *)malloc(n*sizeof(ll));
b=(ll *)malloc(n*sizeof(ll));
for ( i = 0; i < n; i++)
{
    cin>>a[i];
    if(a[i]==0) c++;
}
ll p[c],q[n-c];
for ( i = 0; i < n; i++)
{
    cin>>b[i];
    if(a[i]==0){
        p[j]=b[i];
        j++;
    }else{
        q[r]=b[i];
        r++;
    }

}
sort(p,p+c);
sort(q,q+n-c);
if(c==n-c){
    sort(b,b+n);
    total=b[0];
    for ( i = 1; i < n; i++)
    {
        total+=(2*b[i]);
    }
    
}else if(c==0 || c==n){
    for ( i = 0; i < n; i++)
    {
        total+=(b[i]);
    }
}else if(c<n-c){
    for ( i = 0; i < c; i++)
    {
        total+=(2*p[i]);
    }
    for (i = n-c-1; i >(n-2*c-1); i--)
    {
        total+=(2*q[i]);
    }
    for(i=0;i<(n-2*c);i++)
    total+=q[i];
    
    
}else{
    for ( i = 0; i < n-c; i++)
    {
        total+=(2*q[i]);
    }
    for (i = c-1; i >(2*c-n-1); i--)
    {
        total+=(2*p[i]);
    }
    for(i=0;i<(2*c-n);i++)
        total+=p[i];
    
    
}
cout<<total<<endl;
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

// #include<bits/stdc++.h>
// using namespace std;
// //main function
// int main() {
//     int n; 
//     cin>>n; // taking size of vector from user
//     int a;
//     vector<int> v;
//     set<int>t;
//     set<int>::iterator itr=t.begin();
//     // we can also mention size here like
//     // vector<int> v(n);
//     for(int i=0 ; i<n ; i++)
//     {
//         cin>>a;
//         v.push_back(a);
//     }
//     copy(v.begin(),v.end(),inserter(t,t.begin()));
//     for(auto &p : v)
//     {
//         cout<<p<<" ";
//     }
//     cout<<endl;
//     for(auto &tp : t)
//     {
//         cout<<tp<<" ";
//     }
//     cout<<endl;
//     return 0;
// }