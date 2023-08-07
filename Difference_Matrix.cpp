#include <bits/stdc++.h>
#include <iostream>
using namespace std;

void solve()
{
int n,k=1,l=2;
cin>>n;

for (int i = 0; i < n; i++)
{
    for (int j=0;j<n;j++){
        if(k<=n*n) {
            cout<<k<<" ";
            k=k+2;
        }else{
            cout<<l<<" ";
            l=l+2;
        }
    }
    cout<<endl;
}

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


