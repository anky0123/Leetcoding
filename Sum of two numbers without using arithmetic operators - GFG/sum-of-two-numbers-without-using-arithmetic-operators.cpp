//{ Driver Code Starts
//Initial Template for C++
#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
//User function Template for C++

class Solution
{
    public:
    int sum(int a , int b)
    {
        //code here
        int carry = 0;
        int pos = 0;
        int ans = 0;
        while(a!=0 || b!=0)
        {
            int one = 0;
            int x = a%2;
            int y = b%2;
            if(x) one++;
            if(y) one++;
            if(carry) one++;
            carry = one/2;
            if(one%2)  ans^= (1<<pos);
            a = a>>1; b = b>>1;
            pos++;
        }
        if(carry) ans^=(1<<pos);
        return ans;
    }
    
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int a,b;
        cin >> a>>b;
        
        Solution ob;
        cout<< ob.sum(a,b) <<"\n";
        
    }
    return 0;
}

// } Driver Code Ends