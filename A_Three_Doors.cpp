#include<iostream>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int x,a,b,c;
        cin >>x>>a>>b>>c;
        if((x==1 && a==2 && b==3)||(x==1 && a==3 && c==2)||(x==2 && b==1 && a==3)||(x==2 && b==3 && c==1)||(x==3 && c==2 && b==1)||(x==3 && c==1 && a==2)) 
        cout<<"YES"<<endl;
        else
        cout<<"NO"<<endl;
    }
    
}