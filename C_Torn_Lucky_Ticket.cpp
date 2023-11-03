#include <bits/stdc++.h>
#include <cstring>
using namespace std;
#define ll long long
#define ld long double
#define endl '\n'
bool checklucky(string s){
    int n1=0,n2=0,i=0,j=s.size()-1;
    while (i<j)
    {
        n1+=(s[i]-'0');
        n2+=(s[j]-'0');
        i++;
        j--;
    }
    return n1==n2;
}
void solve()
{
    ll n, count=0;
    cin>>n;
    vector<string> odd;
    vector<string> even;
    string temp;
    for (int i = 0; i < n; i++)
    {
        cin>>temp;
        if(temp.size()%2==0) even.push_back(temp);
        else odd.push_back(temp);
    }
    unordered_map<string,int> mp;
    for(int i=0;i<even.size();i++){
        for (int j = i+1; j <even.size() ; j++)
        {
            if(checklucky(even[i]+even[j])) count++;
            if(checklucky(even[j]+even[i])) count++;
        }
    }
    for(int i=0;i<odd.size();i++){
        for (int j = i+1; j <odd.size() ; j++)
        {
            if(checklucky(odd[i]+odd[j])) count++;
            if(checklucky(odd[j]+odd[i])) count++;
        }
    }
    cout<<n+count<<endl;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
        solve();

    return 0;
}