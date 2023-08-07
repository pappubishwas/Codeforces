//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
//User function Template for C++

int arr[1000010][4]; // 1e6 + 10

class Solution{   
public:
    int countWays(vector<vector<int>>& ranges) {
        int i,j,n=0,c=0,sum=1;
        n=ranges.size();
        for(i=0;i<n;i++){
            for ( j = i; j < n; j++)
            {
                if((ranges[j][0]>=ranges[i][0] && ranges[j][0]<=ranges[i][1])||(ranges[j][1]>=ranges[i][0] && ranges[j][1]<=ranges[i][1])) c++;
            }
            
        }
        for ( i = 1; i <= c; i++)
        {
            sum*=i;
        }
        
    }
};

//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int N;

        vector<vector<int>> ranges={{1,3},{10,20},{2,5},{4,8}};
        Solution ob;
        cout << ob.countWays(ranges) << endl;
    }
    return 0; 
}

// } Driver Code Ends