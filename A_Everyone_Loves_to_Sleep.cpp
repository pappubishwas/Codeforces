#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define endl '\n'
void solve()
{
int n,H,M;
cin>>n>>H>>M;
int h[n],m[n],minih[n],minim[n];
for(int i=0;i<n;i++)
    cin>>h[i]>>m[i];

for(int i=0;i<n;i++)
{
    if((H<h[i]) || (H==h[i] && M<=m[i])){
    if(M<=m[i]){
        minih[i]=(h[i]-H);
        minim[i]=(m[i]-M);
    }else{
        minih[i]=(h[i]-H-1);
        minim[i]=(m[i]-M+60);
    }
    }else if((H>h[i]) || (H==h[i] && M>=m[i])){
       // minim[i]=60-M+m[i];
        if(M>0){
            minim[i]=60-M+m[i];
            minih[i]=(23-H+h[i]);
        }
        else{
            minim[i]=m[i];
            minih[i]=(24-H+h[i]);
        }   
        
        if((minim[i])>=60){
            minim[i]=minim[i]-60;
            minih[i]=minih[i]+1;
        }    

    }
}
int counth=minih[0] , countm=minim[0];

for (int i = 1; i < n; i++)
{
    if((minih[i]<counth) || (minih[i]==counth && countm>minim[i])){
    counth=minih[i];
    countm=minim[i];
    }
}
cout<<counth<<" "<<countm<<endl;

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