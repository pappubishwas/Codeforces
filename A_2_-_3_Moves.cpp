#include<iostream>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n,te;
        cin>>n;
        te=n/3;
        if(n==1) 
        te=2;
        else if(n%3!=0) 
        te++;
        
        cout<<te<<endl;
    }
    
}