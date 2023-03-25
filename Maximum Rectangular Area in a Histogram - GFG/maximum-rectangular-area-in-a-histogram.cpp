//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
    //Function to find largest rectangular area possible in a given histogram.
    long long getMaxArea(long long arr[], int n)
    {
        // Your code here
        vector<long long> right_smaller;
        vector<long long > left_smaller;
        stack <pair<long long , long long>> rs;
        stack <pair<long long , long long>> ls;
        
        for(long long i= n-1 ;i>= 0 ;i--)
        {
            if(rs.empty())  right_smaller.push_back(n);
            else if(!rs.empty() && rs.top().first < arr[i]) 
            right_smaller.push_back(rs.top().second);
            else if(rs.top().first >= arr[i] && !rs.empty())
            {
                while(!rs.empty() && rs.top().first >= arr[i] )
                rs.pop();
                rs.empty() ? right_smaller.push_back(n) : right_smaller.push_back(rs.top().second);
            }
            rs.push({arr[i], i});
        }
        reverse(right_smaller.begin(), right_smaller.end());
        
        
        for(long long i=0;i<n;i++) 
        {
            if(ls.empty()) left_smaller.push_back(-1);
            else if(ls.top().first < arr[i] && !ls.empty() )
            left_smaller.push_back(ls.top().second);
            else if(!ls.empty() && ls.top().first >= arr[i] )
            {
                while(!ls.empty() && ls.top().first >= arr[i])
                ls.pop();
                ls.empty() ? left_smaller.push_back(-1) : left_smaller.push_back(ls.top().second);
            }
            ls.push({arr[i], i});
        }
        long long value =0; 
        for(int i=0 ;i<n;i++)
        {
            value = max(value, arr[i] * (right_smaller[i] - left_smaller[i] -1) );
        }
        return value;
    }
};


//{ Driver Code Starts.

int main()
 {
    long long t;

    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        
        long long arr[n];
        for(int i=0;i<n;i++)
            cin>>arr[i];
        Solution ob;
        cout<<ob.getMaxArea(arr, n)<<endl;
    
    }
	return 0;
}

// } Driver Code Ends