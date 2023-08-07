#include <bits/stdc++.h> // header file includes every Standard library
using namespace std;

int main() {

	int G,S,A,B;
    cin>>G>>S>>A>>B;
    if((G*A)>=(S*B))
    cout<<"Gold"<<endl;
    else
    cout<<"Silver"<<endl;
    
    return 0;
}