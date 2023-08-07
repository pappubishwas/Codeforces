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
    std::string s,p;
    unsigned long d ,d1,d2=0,n=0;
    cin >> d;
    cin>>s;
for ( int i = 0; i < d-1; i++)
 {
    if(s[i+1]=='0') {
        d2++;
n++;
break;
    }
    n++;
 }

//  d1 = std::bitset<17>(s).to_ulong();
//  d2 = std::bitset<17>(p).to_ulong();
//  if((d2-d1)==0) cout<<d<<endl;
//  else{
// n=log2(d1/(d2-d1));
if(d2<1)cout<<d<<endl;
else
cout <<n<<endl;
 
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

// for ( int i = 0; i < d-1; i++)
//  {
//     if(s[i+1]=='1'){
//     p.insert (p.end(),'0'); 
//     } 
//     else {
//     p.insert (p.end(),'1');
//     }
//  }


// #include <iostream>
// #include <bitset>
// int main()
// {
// std::string binary = std::bitset<8>(128).to_string(); //to binary
// std::cout<<binary<<"\n";
// unsigned long decimal = std::bitset<8>(binary).to_ulong();
// std::cout<<decimal<<"\n";
// return 0;
// }