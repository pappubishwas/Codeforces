#include <iostream>
#include <sstream>
using namespace std;

class Student
{
    int a,s;
    string fn,ln;
    public:
    void set_age(int p){
        a=p;
    }
    void set_standard(int p){
        s=p;
    }
    void set_first_name(string p){
        fn=p;
    }
    void set_last_name(string p){
        ln=p;
    }
    int get_age(){
        return a;
        //cout<<a<<endl;
    }
    int get_standard(){
        return s;
        //cout<<s<<endl;
    }
    string get_first_name(){
        return fn;
        //cout<<fn<<endl;
    }
    string get_last_name(){
        return ln;
        //cout<<ln<<endl;
    }
    void to_string(){
       cout<<a<<","<<fn<<","<<ln<<","<<s<<endl; 
    }

};

int main() {
    int age, standard;
    string first_name, last_name;
    
    cin >> age >> first_name >> last_name >> standard;
    
    Student st;
    st.set_age(age);
    st.set_standard(standard);
    st.set_first_name(first_name);
    st.set_last_name(last_name);
    
    cout << st.get_age() << "\n";
    cout << st.get_last_name() << ", " << st.get_first_name() << "\n";
    cout << st.get_standard() << "\n";
    cout << "\n";
    st.to_string();
    
    return 0;
}