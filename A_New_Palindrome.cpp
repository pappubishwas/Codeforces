#include <bits/stdc++.h>
#include <cstring>
using namespace std;
#define ll long long
#define ld long double
#define endl '\n'
void solve()
{
int i,n,j=0,l;
string s;
cin>>s;
l=s.length();
 std::set<char> a;
 for(i=0;i<l;i++){
a.insert(s[i]);
}
//  for(auto &str: a){
//     cout<<str;
//  }

 if(l%2==0){
    if(a.size()>1)cout<<"YES"<<endl;
    else cout <<"NO"<<endl;
 }else{
    if(a.size()>2)  cout<<"YES"<<endl;
    else if(a.size()==2){
        for(i=0;i<l/2;i++){
            if(s[l/2]==s[i]){
                j=1;
                break;
            }
        }
        if(j==0) cout<<"NO"<<endl;
        else cout<<"YES"<<endl;
    }
    else cout<<"NO"<<endl;
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