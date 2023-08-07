#include <bits/stdc++.h>
#include <cstring>
using namespace std;
#define ll long long
#define ld long double
#define endl '\n'
void solve()
{
ll n,i,c=0;
cin>>n;
string s;
char ch;
vector<char> v;
cin>>s;
ch=s[0];
v.push_back(ch);
for(i=1;i<n;i++){
    if(c==1){
        v.push_back(s[i]);
        c=0;
        ch=s[i];
        i++;
    }
    if(ch==s[i]){
        c=1;
    }

}
for (auto element : v) {
        cout << element;
    }
    cout<<endl;
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