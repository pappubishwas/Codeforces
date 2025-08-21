#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve()
{
    ll n, c, m;
    cin >> n >> m;
    string s;

    vector<vector<ll>> mat(n, vector<ll>(m, 0));

    ll mx = INT_MIN;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> mat[i][j];
            mx = max(mat[i][j], mx);
        }
    }
    ll row=0,col=0,single=0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (mat[i][j] == mx)
            {
                bool flag=false;
                mat[i][j]=-1;
                for (int k = 0; k < m; k++)
                {
                    if (mat[i][k] == mx)
                    {
                        mat[i][k]=-1;
                        flag=true;
                    }
                }
                if(flag) row++;
                bool flag1=false;
                for (int k = 0; k < n; k++)
                {
                    if (mat[k][j] == mx)
                    {
                        mat[k][j] = -1;
                        flag1=true;
                    }
                }
                if(flag1) col++;
                if(!flag && !flag1) single++;
            }
            if(row+col+single>2 || row==2 || col==2 || (single==1 && (row>1 || col>1))){
                cout<<mx<<endl;
                return;
            }
        }
        
    }
    cout<<mx-1<<endl;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}

