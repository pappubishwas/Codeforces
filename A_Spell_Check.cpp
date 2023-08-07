#include <bits/stdc++.h>
#include<iostream>
#include<string>
using namespace std;
#define ll long long
#define ld long double
#define endl '\n'
void solve()
{
int n,i,c=0;
cin>>n;
string p;
string t= "Timur";
cin>>p;
if(n==5)
{
for(i=0;i<5;i++){
    for (int j = 0; j < 5; j++)
    {
        if(p[j]==t[i]){
        c++;
        break;
        }
    }      
}
if(c==5)
cout<<"YES"<<endl;
else
cout<<"NO"<<endl;

}else
cout<<"NO"<<endl;


    
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