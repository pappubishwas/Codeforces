#include <bits/stdc++.h>
#include <iostream>
using namespace std;

void solve()
{
    long long int n,m,j,i,k,c=0,value,pt;
    cin >> n>>m;
    vector <long long> a(n),p(m),b(n);

    for ( i = 0; i < m; i++)
    {
        cin >>value;
        p.push_back(value);
        
    }
    for ( i = 0; i < n; i++)
    {
        a.push_back(i+1);
        b.push_back(-1);
    }
    pt=n;
    for ( i = 0; i < m; i++)
    {
        j=0;
        c=0;
        while (a[j]!=1)
        {
        
            if(a[j]==p[i]){
                a.erase(a.begin()+j);
                a.insert(a.begin()+0,p[i]);
                c=1;
                break;
            }
            j++;
        }
        
        if(c==0){
            b.erase(b.begin()+pt-1);
            b.insert(b.begin()+pt-1,(i+1));
            a.insert(a.begin()+0,p[i]);
            pt=pt-1;

        }
    }
    for ( i = 0; i < n; i++)
    {
        cout<<b[i]<<" ";
    }
    cout<<endl;
    
    
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



// #include<bits/stdc++.h>
// using namespace std;

// void solve()
// {
//     long long n,m; 
//     cin>>n>>m;
//     vector<long long>vt(m);
//     for(long long i=0; i<m; i++)
//     {
//         cin>>vt[i];
//     }

//     map<long long,long long>mpt;
//     for (long long i=1; i<=n; i++)
//     {
//         mpt[i]=-1;
//     }
//     long long mm=1;
//     long long tp=n;

//     for (long long i=0; i<m; i++)
//     {
//         if(tp==0)
//         {
//             break;
//         }
//         if(mpt.find(vt[i])==mpt.end())
//         {
//             mpt[vt[i]]=1;
//             mpt[tp]=mm;
//             tp--;
//         }
//         mm++;
//     }
//     for(auto x: mpt)
//     {
//         if(x.first<=n)
//         {
//            cout<<x.second<<" ";
//         }
//     }
//     cout<<endl;
// }

// int main()
// {
//     ios_base::sync_with_stdio(false);
//     cin.tie(0);
//     cout.tie(0);
//     long long t;
//     cin>>t;
//     while(t--)
//     { 
//         solve();
//     }
//     return 0;
// }