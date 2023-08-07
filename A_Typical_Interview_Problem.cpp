#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,count=0;
        cin>>n;
        string s;
        cin>>s;
        if(n<3){
            if(n==2 && (s[0]=='B' && s[1]=='B'))
            cout<<"NO"<<endl;
            else cout<<"YES"<<endl;
        }else{
            char p,q,r;
            p=s[0];
            q=s[1];
            r=s[2];
        for (int i = 0; i < 2; i++)
        {
            if(s[i]=='B' && s[i+1]=='B')
            count=1;
        }
        if(s[0]=='F' && s[1]=='F' && s[2]=='F') count=1;
        for (int i = 3; i < n; i++)
        {
            if(s[i]==p){
                i++;
                if(i>=n || s[i]==q ){
                    i++;
                    if(i>=n || s[i]==r){
                        
                        continue;
                    }else{
                        count=1;
                        break;
                    }
                }else{
                    count=1;
                    break;
                }
            }else{
                count=1;
                break;
            }
        }
        if(count==0)cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
        }
    }
}