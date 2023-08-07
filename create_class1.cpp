#include<iostream>
#include <bits/stdc++.h>
using namespace std;
class create
{
    private: 
    int rollNo,total_mark;
    string name;
    static float average,sum,c;
    public:
    void input(){
    //getline(cin,name);
    cout<<"Enter name :";
    cin>>name;  
    fflush(stdin);
    cout<<"Enter Roll :";
    cin >>rollNo;
    cout<<"Enter Mark :";
    cin>>total_mark;
    sum=sum+total_mark;
    c++;
    }
    void output(){
        cout<<"Name :"<<name<<endl;
        cout<<"Roll No :"<<rollNo<<endl;
        cout<<"Total Marks :"<<total_mark<<endl;

    }
    static void displayAvg(){
        average=sum/c;
        cout<<"Average of total_mark : "<<average<<endl;
    }

};
float create::average;
float create::sum;
float create::c;
int main()
{
    int n,i;
    cout<<"Enter the number of student : ";
    cin>>n;
    
    create a[n];
    for(i=0;i<n;i++){
    cout<<"\nThe data of object a["<<i+1<<"] :\n";
    a[i].input();
    }
    for(i=0;i<n;i++){
    cout<<"\nThe data of object a["<<i+1<<"] :\n";
    a[i].output();
    }
    create::displayAvg();


}