#include<iostream>
using namespace std;
int main()
{
        long long int n,m,a,t1,t2;
        cin>>n>>m>>a;
        if (n%a==0)
        {
            t1=n/a;
        }else
            t1=n/a +1;

        if ((m)%a==0)
        {
        t2=(m)/a;
        }else
        t2=(m)/a +1;

        cout<<t1*t2;
        
            
}