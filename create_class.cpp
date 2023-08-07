#include<iostream>
using namespace std;
class create
{
    private: 
    int a;
    static int count1;
    static int count2;

    public:
    void input(int x){
        a=x;
        count1++;
    }
    void output(){
        cout<<a<<endl;
        count2++;
    }
    void displayCount(){
        cout<<"\nThe input called is :  "<<count1<<endl;
        cout<<"The output called is :  "<<count2<<endl;
    }
};
int create::count1;
int create::count2;
int main()
{
    
    create a,b,c;
    a.displayCount();
    a.input(100);
    b.input(200);
    c.input(300);
    a.displayCount();
    cout<<"\nThe data of object a :";
    a.output();
    cout<<"\nThe data of object b :";
    b.output();
    cout<<"\nThe data of object c :";
    c.output();
    a.displayCount();
}