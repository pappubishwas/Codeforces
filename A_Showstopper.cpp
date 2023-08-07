#include <bits/stdc++.h>
#include <iostream>
using namespace std;

void solve()
{
int n,i,j,k,p,q=0,c=0;
cin>>n;
int a[n],b[n];
for(i=0;i<n;i++){
    cin>>a[i];
}
for(i=0;i<n;i++){
    cin>>b[i];
}
k=a[n-1]; p=b[n-1];

for ( i = 0; i < n-1; i++)
{
    if((a[i]>k && a[i]>p) || (b[i]>k && b[i]>p) ){
            c=1;
            break;
    }else if(((a[i]>k && a[i]<=p) && b[i]<=k) || (((b[i]>p && b[i]<=k) && a[i]<=p)))
            continue;
    else if((a[i]>k && a[i]<=p) || (b[i]>p && b[i]<=k)){
            if(q==0){
                k=b[n-1];
                p=a[n-1];
                q=1;
                i--;
            }else{
                c=1;
                break;
            }
    }
}

if(c==0) cout<<"Yes"<<endl;
else cout<<"No"<<endl;

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


