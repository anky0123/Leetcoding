//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{

  public:
	int minDifference(int arr[], int n)  { 
	    int total = accumulate(arr, arr+n, 0);
	    int sum = total/2;
	    
	    vector<vector<int>> dp(n+1, vector<int> (sum+1, 0));
	    
	    for(int i=1;i<=n;i++)
	    {
	        for(int j=0;j<=sum;j++)
	        {
	            if(arr[i-1] <= j) dp[i][j] = max( dp[i-1][j], arr[i-1] + dp[i-1][j-arr[i-1]] );
	            else dp[i][j]  = dp[i-1][j];
	        }
	    }
	    return total - 2*dp[n][sum];
	} 
};


//{ Driver Code Starts.
int main() 
{
   
   
   	int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

        int a[n];
        for(int i = 0; i < n; i++)
        	cin >> a[i];

       

	    Solution ob;
	    cout << ob.minDifference(a, n) << "\n";
	     
    }
    return 0;
}
// } Driver Code Ends