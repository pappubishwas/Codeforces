// #include <bits/stdc++.h>
// #include <iostream>
// using namespace std;

// void solve()
// {
// int i, n,c=0,m=0,e=0,o=0,w=0;
// cin>>n;
// string tan;
// cin>>tan;

// for ( i = 0; i < n; i++)
// {
//     if((tan[i]=='m' || tan[i]=='M') ){
//         m=1;
//             if((tan[i+1]=='m' || tan[i+1]=='M' || tan[i+1]=='e' || tan[i+1]=='E')){
//                 continue;
//             }else{
//                 c=1;
//                 break;
//             }
//     }
//     if((tan[i]=='e' || tan[i]=='E')){
//         e=1;
//             if(tan[i+1]=='o' || tan[i+1]=='O' || tan[i+1]=='e' || tan[i+1]=='E'){
//                 continue;
//             }else{
//                 c=1;
//                 break;
//             }
//     }
//     if((tan[i]=='o' || tan[i]=='O') ){
//         o=1;
//             if(tan[i+1]=='o' || tan[i+1]=='O' || tan[i+1]=='w' || tan[i+1]=='W'){
//                 continue;
//             }else{
//                 c=1;
//                 break;
//             }
//     }
//     if((tan[i]=='w' || tan[i]=='W')){
//         w=1;
//             if((tan[i+1]=='w' || tan[i+1]=='W' ) || tan[i+1]=='\0'){
//                 continue;
//             }else{
//                 c=1;
//                 break;
//             }
//     }

// }

// if(c==1 || o==0 || m==0 || w==0 || e==0) cout<<"NO"<<endl;
// else cout<<"YES"<<endl;

    
// }

// int main()
// {
//     long long tc;
//     cin >> tc;
//     while (tc--)
//     {
//         solve();
//     }
//     return 0;
// }





#include <bits/stdc++.h>
#include <iostream>
using namespace std;

void solve()
{
int i, n,c=0,m=0,e=0,o=0,w=0;
cin>>n;
string tan;
cin>>tan;

for(i=0;i<n;i++){
    tan[i]=tolower(tan[i]);
}
for ( i = 0; i < n; i++)
{
    if(tan[i]=='m' ){
        m=1;
            if((tan[i+1]=='m' || tan[i+1]=='e')){
                continue;
            }else{
                c=1;
                break;
            }
    }
    if(tan[i]=='e'){
        e=1;
            if(tan[i+1]=='o' || tan[i+1]=='O' || tan[i+1]=='e' || tan[i+1]=='E'){
                continue;
            }else{
                c=1;
                break;
            }
    }
    if(tan[i]=='o'){
        o=1;
            if(tan[i+1]=='o' || tan[i+1]=='w'){
                continue;
            }else{
                c=1;
                break;
            }
    }
    if((tan[i]=='w')){
        w=1;
            if((tan[i+1]=='w') || tan[i+1]=='\0'){
                continue;
            }else{
                c=1;
                break;
            }
    }

}

if(c==1 || o==0 || m==0 || w==0 || e==0) cout<<"NO"<<endl;
else cout<<"YES"<<endl;

    
}

int main()
{
    long long tc;
    cin >> tc;
    while (tc--)
    {
        solve();
    }
    return 0;
}




