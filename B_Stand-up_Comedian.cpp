#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define endl '\n'
void solve()
{
ll a,b,c,d;
cin>>a>>b>>c>>d;
ll p,q,j;
p=a;q=a;j=a;
int n=0;
while (n==0)
{
    if(p<=q){
        if(b>=q){
            b=b-q;
            j=j+q;
            p=p+q;
            q=0;
        }else{
            j=j+b;
            q=q-b;
            p=p+b;
            b=0;
        }
    }else{
        if(c>=p){
            c=c-p;
            j=j+p;
            q=q+p;
            p=0;
        }else{
            j=j+c;
            p=p-c;
            q=q+p;
            c=0;
        }        
    }

    if((b==0 && p==0)|| (c==0 && q==0) || (c==0 && b==0) || (p==0 && q==0)) n=1;
}
if(p!=0 && q!=0){
    if(p>=q){
        if(q<=d){
            j=j+q;
            d=d-q;
        }else{
            j=j+d;
            d=0;
        }
    }else{
        if(p<=d){
            j=j+p;
            d=d-p;
        }else{
            j=j+p;
            d=0;
        }        
    }
}
if(c==0 && b==0 &&d==0) cout<<j<<endl;
else cout<<j+1<<endl;
    

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