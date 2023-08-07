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
int n,c,a,i,co,total=0;
cin>>n>>c;
vector<int>v;
set<int> s;
set<int>::iterator itr=s.begin(); //intialize a set iterator
for ( i = 0; i < n; i++)
{
    cin>>a;
    v.push_back(a);  //insert a element in vector
    s.insert(a);   // insert a element in set
}
for(auto &t:s){
    co=count(v.begin(),v.end(),t);//count how many times a element in a vector
    if(co>=c)
    total=total+c;
    else
    total=total+co;
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