#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define endl '\n'
void solve()
{
    int x,b[10],temp,i=0,k=9;
    cin>>x;
    if(x<10) cout<<x<<endl;
    else if(45<x) cout<<-1<<endl;
    else{
        temp=x;
        while(temp>0 && i<10){
            
            if(temp<k){
                b[i]=temp;
            }else{
                b[i]=k;
            }
            temp=temp-k;
            k=k-1;
            i++;
        }
        for(int j=i-1;j>=0;j--)
            cout<<b[j];
        cout<<endl;    
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