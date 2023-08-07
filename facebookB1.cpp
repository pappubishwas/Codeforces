#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define endl '\n'
void solve()
{
        int r,c,i,j,t=0;
        cin>>r>>c;  
        char p[100][100];
        for ( i = 0; i < r; i++)
        {
            for ( j = 0; j < c; j++)
            {
                cin>>p[i][j];

                if(p[i][j]=='^') t++;
            }
        }
        if((r==1 || c==1 )&& t!=0){
            cout<<"Impossible"<<endl;

        }else{
        cout<<"Possible"<<endl;
        if((r==1 ||  c==1) && t==0){
        for ( i = 0; i < r; i++){
            for ( j = 0; j < c; j++){
                cout<<".";
            }
            cout<<endl;
        }
        }else{
        for ( i = 0; i < r; i++){
            for ( j = 0; j < c; j++){
                cout<<"^";
            }
            cout<<endl;
        }
        }
        }
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    ll t;
    int k;
    cin >> t;
    for (k=0;k<t;k++)
    {
        cout<<"Case #"<<k+1<<": ";
        solve();
    }
    return 0;
}