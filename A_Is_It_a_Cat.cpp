

#include <bits/stdc++.h>
#include <iostream>
using namespace std;
#define f(i,a,b) for(long long i=a;i<b;i++)
#define rf(i,a,b) for(long long i=a;i>=b;i--)
#define ll long long
#define mp make_pair
#define pb push_back
#define vll vector<long long>
#define vvl vector<vll>
#define pll pair<ll,ll>
#define vc vector
#define fi first
#define se second
#define lb lower_bound
#define POW(a,b) (ll)(pow(a,b)+0.5)
#define gcd __gcd
#define to_lowercase(s) transform(s.begin(), s.end(), s.begin(), ::tolower)
#define to_uppercase(s) transform(s.begin(), s.end(), s.begin(), ::toupper)





void solve()
{
    int n;
    cin>>n;
    string s,y="";
    cin>>s;
    to_lowercase(s);
    s+="#";
    f(i,0,n)
       if(s[i]!=s[i+1]) y+=s[i];
       //cout<<y<<endl;
     if(y=="meow") cout<<"YES"<<endl;
     else cout<<"NO"<<endl; 
}

int main()
{
    long long tc;
    cin >> tc;
    while (tc--)
    {
        solve();
    }
    return 0;
}




