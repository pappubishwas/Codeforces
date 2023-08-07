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
string s1,s2;
cin>>s1>>s2;
int x1,x2,len1,len2;
len1=s1.length();len2=s2.length();
if(s1[len1-1]==s2[len2-1]){
    if(s1[len1-1]=='S'){
        if(len1>len2) cout<<"<"<<endl;
        else if(len2>len1) cout<<">"<<endl;
        else cout<<"="<<endl;
    }else if(s1[len1-1]=='L'){
        if(len1>len2) cout<<">"<<endl;
        else if(len2>len1) cout<<"<"<<endl;
        else cout<<"="<<endl;
    }else cout<<"="<<endl;
}else{
    if(s1[len1-1]=='S')cout<<"<"<<endl;
    else if (s1[len1-1]=='L') cout<<">"<<endl;
    else{
        if(s2[len2-1]=='S') cout<<">"<<endl;
        else  cout<<"<"<<endl;
    }
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

