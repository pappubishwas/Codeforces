#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
#define int long long
#define INF (int)1e18

mt19937_64 RNG(chrono::steady_clock::now().time_since_epoch().count());

template <class T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

int rndRange(int l, int r) { return RNG() % (r - l + 1) + l; }

vector<int> lp;
vector<int> pr;
int N = 10000000;

void Solve()
{
    int n, l, r;
    cin >> n >> l >> r;
    l--;r--;
    vector<int> pap(n);

    for(int i = 0; i < n; i++)
    {
        cin >> pap[i];
    }
    vector<int> b,c;
	for(int i = l; i < n; i++) { // take from l to n all the elment
		b.push_back(pap[i]);
	}
	for(int i = 0; i <= r; i++) { // take all from 0 to r
		c.push_back(pap[i]);
	}
	sort(b.begin(), b.end());
	sort(c.begin(), c.end());
    // we have two option either we will take from left and take inside of segment or right right and take insdie the segment
	int sum1 = accumulate(b.begin(), b.begin() + (int)(r-l+1), 0LL); //we can take all smallest values from right side of r 
	int sum2 = accumulate(c.begin(), c.begin() + (int)(r-l+1), 0LL); // we can take all smalles values from left side of l
 
	cout << min(sum1, sum2) << endl;
}

int32_t main()
{
    auto begin = chrono::high_resolution_clock::now();
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t = 1;
    cin >> t;
    for (int i = 1; i <= t; i++)
    {
        Solve();
    }

    auto end = chrono::high_resolution_clock::now();
    auto elapsed = chrono::duration_cast<chrono::nanoseconds>(end - begin);
    return 0;
}