//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    long long solve(int N, int K, vector<long long> GeekNum) {

        long long sum = 0;
        int i,j=0;
        if (K == 1)
            return GeekNum[0];
        else if (K == N)
        {
            return GeekNum[K - 1];
        }
        else
        {
            for(i=0;i<K;i++)sum+=GeekNum[i];
            
            for (i = K; i < N; i++)
            {

                
                GeekNum.push_back(sum);
                sum=sum+(sum-GeekNum[j]);
                j++;
            }

            return GeekNum[N - 1];
        }
    }
};


//{ Driver Code Starts.


//{ Driver Code Starts.

int main() {
    int T;
    cin >> T;
    while (T--) {
        int N, K;
        cin >> N >> K;

        vector<long long> GeekNum(K);

        for (int i = 0; i < K; i++) cin >> GeekNum[i];

        Solution ob;
        cout << ob.solve(N, K, GeekNum) << "\n";
    }
    return 0;
}

// } Driver Code Ends