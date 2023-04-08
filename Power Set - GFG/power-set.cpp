//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
	public:
		vector<string> AllPossibleStrings(string A){
		    // Code here
		vector<string> ans;
        int n = pow(2, A.size());
        for(int i=1;i<n;i++)
        {
            string temp;
            for(int j =0;j<A.size();j++)
            {
                if(i& (1<<j)) temp+=A[j];
            }
            ans.push_back(temp);
        }
        sort(ans.begin(), ans.end());
        return ans;
		}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		string s;
		cin >> s;
		Solution ob;
		vector<string> res = ob.AllPossibleStrings(s);
		for(auto i : res)
			cout << i <<" ";
		cout << "\n";

	}
	return 0;
}
// } Driver Code Ends