//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

// } Driver Code Ends
class Solution{
public:
    int *findTwoElement(int *arr, int n) {
        // code here
        int sum = 0;
        for(int i=0;i<n;)
        {
            if(arr[i] == i+1)  i++;
            else 
            {
                if(arr[arr[i]-1] == arr[i]) i++;
                else 
                {
                 swap(arr[i], arr[arr[i]-1]);
                }
            }
        }
        int a,b;
        int temp[2];
        for(int i=0;i<n;i++)
        {
            if(arr[i]!=i+1) 
            {
                temp[0] = arr[i];
                temp[1] = i+1;
            }
        }
        
        int *ans = temp;
        return ans;
        
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
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        Solution ob;
        auto ans = ob.findTwoElement(a, n);
        cout << ans[0] << " " << ans[1] << "\n";
    }
    return 0;
}
// } Driver Code Ends