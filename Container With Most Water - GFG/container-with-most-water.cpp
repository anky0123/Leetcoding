//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;
// int maxArea(int A[], int len);

// } Driver Code Ends
//User function template for C++

long long maxArea(long long height[], int len)
{
    // Your code goes here
    int ans = 0;
        for(int i=0,j = len-1; i<j;)
        {
            int h = min(height[i], height[j]);
            ans = max(ans, h * (j-i));
            if((height[i] ) >= height[j] ) j--;
            else i++;
        }
        return ans;
}

//{ Driver Code Starts.

// Driver code
int main()
{
	int t;
	cin>>t;
	while(t--)
    {
        int n;
        cin>>n;
        long long arr[n];
        for(int i=0;i<n;i++)
            cin>>arr[i];
        cout<<maxArea(arr,n)<<endl;
    }
return 0;
}

// } Driver Code Ends