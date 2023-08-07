#include<iostream>
using namespace std;
int main()
{
    int  t;
    cin >> t;
    while (t--)
    {
        long long int i,j,k,sum;
        cin>>i>>j;
        sum=(j*(j+1))/2;
        for(k=2;k<=i;k++)
        {
            sum=sum + k*j;
        }
        cout<<sum<<endl;
        printf("%.0lf\n",sum);
    }
    
}