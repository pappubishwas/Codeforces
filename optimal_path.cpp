#include<iostream>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        double sum=0;
        int i,j,k,m,p=1;
        cin>>i>>j;
        double a[i][j];
        for ( k = 0; k <i; k++)
        {
            for(m=0;m<j;m++)
            {
                a[k][m]=p;
                p++;
            }
        }
        
        for ( k = 0; k <j; k++)
        {
            sum=sum+a[0][k];
        }
        for ( k = 1; k <i; k++)
        {
            sum=sum+a[k][j-1];
        }
        printf("%.0lf",sum);
        //cout<<sum<<endl;
    }
    
}