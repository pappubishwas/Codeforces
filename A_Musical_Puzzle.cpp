#include <bits/stdc++.h>
#include <cstring>
using namespace std;
#define ll long long
#define ld long double
#define endl '\n'
void solve()
{
int n,i,j;
cin>>n;
string s;
cin>>s;
std::set<string> st;
for(i=0;i<n-1;i++){
    string r = s.substr(i, 2);
    st.insert(r);

}

int l=st.size();
cout<<l<<endl;
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