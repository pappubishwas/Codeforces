// #include <bits/stdc++.h>
// using namespace std;
// #define ll long long
// #define ld long double
// #define endl '\n'
// void solve()
// {
//     string s, st = "";
//     cin >> s;
//     int n, t, i = 0, k = 0;
//     n = s.length();
//     t = 2 * n;

//     if (n >= 3 && s[0] == '(' && s[1] == ')')
//     {
//         if (s[2] == ')')
//             st = st + "()()";
//         else
//             st = st + "(())";
//         i = 4;
//     }
//     if (n >= 3 && s[0] == ')' && s[1] == '(')
//     {
//         if (s[2] == ')')
//         {
//             st = st + "((()))";
//             i = 6;
//         }
//         else
//         {
//             st = st + "(())";
//             i = 4;
//         }
//     }
//     while (i < t)
//     {
//         if (i % 2 == 0)
//             st = st + '(';
//         else
//             st = st + ')';

//         i++;
//     }
//     if (n == 2 && s == "()")
//         cout << "NO" << endl;
//     else if (n == 2 && s[0] == ')' && s[1] == '(')
//     {
//         cout << "YES" << endl;
//         cout << "(())" << endl;
//     }
//     else
//     {
//         cout << "YES" << endl;
//         cout << st << endl;
//     }
// }
// int main()
// {
//     ios::sync_with_stdio(false);
//     cin.tie(0);
//     cout.tie(0);
//     ll t;
//     cin >> t;
//     while (t--)
//     {
//         solve();
//     }
//     return 0;
// }








#include <bits/stdc++.h>
using namespace std;

void solve(){
	string S;
	cin >> S;
	int N = (int)S.size();
	string c1;
	for(int i = 0; i < N; i++) c1 += "()";
	string c2 = string(N, '(') + string(N, ')');
	if(c1.find(S) == string::npos){
		cout << "YES" << '\n';
		cout << c1 << '\n';
	} else if(c2.find(S) == string::npos){
		cout << "YES" << '\n';
		cout << c2 << '\n';
	} else {
		cout << "NO" << '\n';
	}
}

int main(){
	ios_base::sync_with_stdio(false), cin.tie(nullptr);
	int T;
	cin >> T;
	while(T--) solve();
}