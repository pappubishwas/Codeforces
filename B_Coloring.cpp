#include <bits/stdc++.h>
using namespace std;
int t, n, m, k, a[100005], i, j;
string s;
int main()
{
    cin >> t;
    while (t--)
    {
        cin >> n >> m >> k;
        for (i = 0, j = 0; i < m; i++)
            cin >> a[i];
        sort(a, a + m);
        if (a[m - 1] <= n / k + 1 && a[m - 1 - n % k] <= n / k)
            cout << "YES\n";
        else
            cout << "NO\n";
    }
}



// #include <bits/stdc++.h>
// using namespace std;

// int main() {
// 	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
// 	int t;
// 	cin>>t;
// 	while (t--) {
// long long i,j,k,m,n;
// cin>>n>>m>>k;
// long long a[m];

// for(i=0;i<m;i++)
// cin>>a[i];
// if(n%k==0) j=n/k;
// else j=n/k+1;
// sort(a,a+m);
// if(a[m-1]>j)cout<<"NO"<<endl;
// else cout<<"YES"<<endl;
// 		}
// 	return 0;
// }