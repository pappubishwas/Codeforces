// #include <bits/stdc++.h> // header file includes every Standard library
// using namespace std;

// int main() {
// int T;
// cin>>T;
// while (T--)
// {
//     int N,k=0,q=0,t=0,i;
//     cin>>N;
//     string p;
//     cin>>p;
//     for ( i = 0; i < N; i++){
//         if(p[i]=='1')
//             k++;

//         if(p[i]=='0' && i<N/2)
//             q++;
//         if(p[i]=='0' && i>N/2)
//             t++;



//     }
    
    
//     if(k==1 || (k==2 && N!=2) || k==3 || k==5 || (k>5 && (k/2)%2!=0) || (q%2!=0 && t%2!=0))
//     cout<<0<<endl;
//     else
//     cout<<1<<endl;
    
// }
//     return 0;
// }



#include <bits/stdc++.h> // header file includes every Standard library
using namespace std;

int main() {
int T;
cin>>T;
while (T--)
{
    int N,k=0,q=0,t=0,i;
    cin>>N;
    string p;
    cin>>p;
    for ( i = 0; i < N; i++){
        if(p[i]=='1')
            k++;

        if(p[i]=='0' && i<N/2)
            q++;
        if(p[i]=='0' && i>N/2)
            t++;



    }
    
    
    if(k==1 || (k==2 && N!=2) || k==3 || k==5 || (k>5 && (k/2)%2!=0) || (q%2!=0 && t%2!=0))
    cout<<0<<endl;
    else
    cout<<1<<endl;
    
}
    return 0;
}


// #include <bits/stdc++.h> // header file includes every Standard library
// using namespace std;

// int main() {
// int T;
// cin>>T;
// while (T--)
// {
//     int N,k=0,q=0,t=0,i;
//     cin>>N;
//     string p;
//     cin>>p;
//     for ( i = 0; i < N; i++){
//         if(p[i]=='1')
//             k++;

//     }
    
    
//     if(k==1  || (k==2 && N!=2) || k==3 || k==5 || (k>5 && (k/2)%2!=0) )
//     cout<<0<<endl;
//     else
//     cout<<1<<endl;
    
// }
//     return 0;
// }