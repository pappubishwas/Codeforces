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
ll i,n;
cin >>n;
ll a[n];
if(n==3) cout <<-1<< endl;
else if(n==5){
    cout<<"5 4 1 2 3"<<endl;
}
else if(n%2==0){
    for(i=n;i>0;i--){
        cout<<i<<" ";
    }
    cout<<endl;
}else{
    for(i=n;i>0;i--){
        if(i<4) cout<<i<<" ";
        else if(i%2==1)
        cout<<i-1<<" ";
        else cout<<i+1<<" ";
    }
    cout<<endl;
}
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

