// #include<iostream>
// using namespace std;

// class Student
// {
//     int sub[5],sum;
//     public:
//     void input(){
//         for(int i=0;i<5;i++)
//         cin>>sub[i];
//     }
//     int totalScore()
//     {
//         for (int i = 0; i < 5; i++)
//         {
//             sum+=sub[i];
//         }
//         return sum;
        
//     }

// };

// int main()
// {
//     int n,i;
//     cin>>n;
//     Student *s = new Student[n]; 
//     for ( i = 0; i < n; i++)
//     {
//         s[i].input();
//     }
//     int ks=s[0].totalScore();
//     int c=0;
//     for ( i = 1; i < n; i++)
//     {
//         if((s[i].totalScore())>ks) c++;
//     }
//     cout<<1<<endl;
    
// }

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <cassert>
using namespace std;

class Student
{
    int sub[5],sum;
    public:
    void input(){
        for(int i=0;i<5;i++)
        cin>>sub[i];
    }
    int calculateTotalScore()
    {
        for (int i = 0; i < 5; i++)
        {
            sum+=sub[i];
        }
        return sum;
        
    }

};
int main() {
    int n; // number of students
    cin >> n;
    Student *s = new Student[n]; // an array of n students
    
    for(int i = 0; i < n; i++){
        s[i].input();
    }

    // calculate kristen's score
    int kristen_score = s[0].calculateTotalScore();

    // determine how many students scored higher than kristen
    int count = 0; 
    for(int i = 1; i < n; i++){
        int total = s[i].calculateTotalScore();
        if(total > kristen_score){
            count++;
        }
    }

    // print result
    cout << count;
    
    return 0;
}