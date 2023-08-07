// #include <bits/stdc++.h>
// #include<iostream>
// #include<algorithm>
// #include <numeric>
// using namespace std;
// #define ll long long
// #define ld long double
// #define endl '\n'
// int fact(int n) {
//    if ((n==0)||(n==1))
//    return 1;
//    else
//    return n*fact(n-1);
// }
// void solve()
// {
//     std::string s;
//     unsigned long d ,d1,d2=0,n=0;
//     cin>>s;

// for ( int i = 0; s[i+1]!='\0'; i++){    
//     if(s[i+1]!=s[i])
//         d2++;
// }

// if(d2<3)cout<<d2+1<<endl;
// else{
// d=(fact(d2-1)/(fact(d2-3)*2));
// cout<<d+d2+1<<endl;
// }


// }
// int main()
// {
//     ios::sync_with_stdio(false);
//     cin.tie(0);
//     cout.tie(0);
//     ll t;
//     cin >> t;
//     while (t--)
//     {
//         solve();
//     }
//     return 0;
// }



#include<bits/stdc++.h>
#define int long long
using namespace std;
bool a[100001];

int dp[100001][2];
void solve()
{
   int n;string s;
   
   cin >> s;n=s.size();
   
   for(int i=1;i<n;++i)
      a[i]=s[i]!=s[i-1];
      
   dp[0][0]=1;
   for(int i=1;i<n;++i)
   {
      dp[i][0]=(dp[i-1][0]+dp[i-1][1])%998244353;
      if(a[i]==1) dp[i][1]=dp[i-1][0];
      
      else dp[i][1]=0;
   }
   cout << (dp[n-1][0]+dp[n-1][1])%998244353 << endl;
}
signed main() 
{
   int T;cin >> T;
   while(T--) solve();
}