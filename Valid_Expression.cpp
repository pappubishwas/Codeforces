#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n,m;
        cin >> n >> m;
        int i,j,k;
        if(m>n && m-n!=1)cout<<-1<<endl;
        else if(m-n==1){
            for(i=0;i<n;i++)
            cout<<'+';
            cout<<endl;
        }
        else if(m==n){
            cout<<'*';
            for(i=1;i<n;i++)
            cout<<'+';
            cout<<endl;
        }else if(n>m){
            if(m<0){
                if(abs(m)>=n)cout<<-1<<endl;
                else{
                    for ( i = 0; i < n-abs(m)-1; i++)
                    {
                        cout<<'*';
                    }
                    for ( i = 0; i < abs(m)+1; i++)
                    {
                        cout<<'-';
                    }
                    
                    cout<<endl;
                }
            }else{
                if(m==1){
                    for ( i = 0; i < n-2; i++)
                    {
                        cout<<'*';
                    }
                    cout<<'+'<<'-'<<endl;

                    
                }else{
                    for ( i = 0; i <= n-m; i++)
                    {
                        cout<<'*';
                    }
                    for ( i = 0; i < m; i++)
                    {
                        cout<<'+';
                    }
                    cout<<endl;
                    
                }
            }
        } 


    }
}
