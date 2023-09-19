//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution{
  public:
    int cut(int price[], int n, int length, vector<vector<int>>&dp)
    {
        if(n == 0) return 0;
        if(dp[n][length]!=0) return dp[n][length];
        if(n <= length) return dp[n][length] =  max ((price[n-1]  + cut(price, n, length - n, dp)), cut(price, n-1, length, dp));
        else return dp[n][length] =  cut(price, n-1, length, dp);
    }
    int cutRod(int price[], int n) {
        //code here
        vector<vector<int>> dp(n+1, vector<int>(n+1, 0));
        return cut(price, n, n, dp);
        
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++) 
            cin >> a[i];
            
        Solution ob;

        cout << ob.cutRod(a, n) << endl;
    }
    return 0;
}
// } Driver Code Ends