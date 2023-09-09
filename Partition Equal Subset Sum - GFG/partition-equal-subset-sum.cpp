//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int equalPartition(int N, int nums[])
    {
        int sum = accumulate(nums, nums+N, 0);
        if(sum%2 != 0) return false;
        else sum/=2;
        int n = N;
        vector<vector<bool>> dp(n+1, vector<bool>(sum+1, false));

        for(int i =0;i<= n;i++) dp[i][0] = true;

        for(int i = 1;i<=n; i++)
        {
            for(int j = 1;j<=sum; j++ )
            {
                if(nums[i-1] <= j) dp[i][j] = dp[i-1][j] || dp[i-1][j - nums[i-1]];
                else dp[i][j] = dp[i-1][j];
            }
        }
        return dp[n][sum];
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        int arr[N];
        for(int i = 0;i < N;i++)
            cin>>arr[i];
        
        Solution ob;
        if(ob.equalPartition(N, arr))
            cout<<"YES\n";
        else
            cout<<"NO\n";
    }
    return 0;
}
// } Driver Code Ends