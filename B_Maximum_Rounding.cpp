#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define endl '\n'
void solve()
{
    int n;
    cin >> n;
    vector<int> v;
    int i, index;
    int m = n;
    while (m > 0)
    {
        int temp = m % 10;
        m = m / 10;
        v.insert(v.begin(), temp);
    }
v.insert(v.begin(), 0);
    int size = v.size();
    // index=n;
    // if(v[0]>=5){
    //     v.clear();
    //     v.push_back(1);
    //     for ( i = 0; i <size; i++)
    //     {
    //         v.push_back(0);
    //     }
    //     size++;
    // }else{
    //     for(i=size-2;i>=0;i-- ){
    //         if(v[i+1]>=5){
    //             index=i;
    //             if(v[i]==9)
    //                v[i]=0;
    //             if(i>0)
    //             v[i-1]++;

    //         }
    //     }
    //     for ( i = index; i < size; i++)
    //     {
    //         v[i]=0;
    //     }

    // }

int tp=size;

    if(v[1]>=5){
        v.clear();
        v.push_back(1);
        for ( i = 1; i <size; i++)
        {
            v.push_back(0);
        }
    
    }
    else{
        /* code */
        for ( i = 1; i < size; i++)
        {
            if(v[i+1]>=5){
                
                v[i]=0;
                tp=i;
                v[i-1]++;
                size=i-1;
                i=i-2;
                
    
            }
        }

        for ( i = tp; i <v.size(); i++)
        {
            v[i]=0;
        }
    
    
    }


    for (i = 1; i < v.size(); i++)
    {if(v[0]!=0) cout<<v[0];
        cout << v[i];
    }
    cout << endl;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    ll t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}