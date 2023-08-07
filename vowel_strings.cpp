#include <bits/stdc++.h>
#include <cstring>
using namespace std;
#define ll long long
#define ld long double
#define endl '\n'
class Solution {
public:
    vector<int> vowelStrings(vector<string>& words, vector<vector<int>>& queries) {
        int wlen,qlen;
       // qlen=queries.length;
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    vector<string> wrods=["aba","bcb","ece","aa","e"];
    vector<vector<int>> queries=[[0,2],[1,4],[1,1]];
    vector<int> ans;
    Solution obj;
    ans=obj.vowelStrings(wrods,queries);
    return 0;
}

