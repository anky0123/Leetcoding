//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};


Node *buildTree(string str) {
    // Corner Case
    if (str.length() == 0 || str[0] == 'N')
        return NULL;

    // Creating vector of strings from input
    // string after spliting by space
    vector<string> ip;

    istringstream iss(str);
    for (string str; iss >> str;)
        ip.push_back(str);

    // Create the root of the tree
    Node *root = new Node(stoi(ip[0]));

    // Push the root to the queue
    queue<Node *> queue;
    queue.push(root);

    // Starting from the second element
    int i = 1;
    while (!queue.empty() && i < ip.size()) {

        // Get and remove the front of the queue
        Node *currNode = queue.front();
        queue.pop();

        // Get the current Node's value from the string
        string currVal = ip[i];

        // If the left child is not null
        if (currVal != "N") {

            // Create the left child for the current Node
            currNode->left = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->left);
        }

        // For the right child
        i++;
        if (i >= ip.size())
            break;
        currVal = ip[i];

        // If the right child is not null
        if (currVal != "N") {

            // Create the right child for the current Node
            currNode->right = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}


// } Driver Code Ends
//User function Template for C++

/*
struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
*/
class Solution {
  public:
  
  
     Node* target = NULL;
     
     void getTargetNode(Node* root, int tar) {
        if(root == NULL) 
            return;
        if(tar == root->data)
        {
            target = root;
            return;
        }
        getTargetNode(root->left, tar);
        getTargetNode(root->right, tar);
    }
    
    int minTime(Node* root, int tar) 
    {
        // Your code goes here
        
           getTargetNode(root, tar);
        
         queue<Node*> q;
        q.push(root);

        // Find parents of all the nodes.
        unordered_map<Node* , Node*>parents;
        while(!q.empty())
        {
            auto temp = q.front();
            q.pop();
            if(temp->left) 
            {
                q.push(temp->left);
                parents[temp->left] = temp;
            }
            if(temp->right) 
            {
                q.push(temp->right);
                parents[temp->right] = temp;
            }
        } 

        //  Make  a visited array;
        unordered_map<Node*, bool> visited;
         
         queue<Node* > qu; 
         qu.push(target);
         int dis = 0;
         visited[target] = true;
        while(!qu.empty())
        {
            dis++;
            int len = qu.size();
            for(int i=0;i<len ; i++)
            {
                auto temp = qu.front();
                qu.pop();
                if(temp->left && !visited[temp->left])  // checking and visiting left node
                {
                    qu.push(temp->left);
                    visited[temp->left] = true;
                }
                if(temp->right && !visited[temp->right]) // checking and visiting right node
                {
                    qu.push(temp->right);
                    visited[temp->right] = true;
                }
                auto baap = parents[temp];
                if(baap && !visited[baap])    // checking and visiting node ka pita 
                {
                    qu.push(baap);
                    visited[baap] = true;
                }
            }
        }
        return dis-1;
    }
};

//{ Driver Code Starts.

int main() 
{
    int tc;
    scanf("%d ", &tc);
    while (tc--) 
    {    
        string treeString;
        getline(cin, treeString);
        // cout<<treeString<<"\n";
        int target;
        cin>>target;
        // cout<<target<<"\n";

        Node *root = buildTree(treeString);
        Solution obj;
        cout<<obj.minTime(root, target)<<"\n"; 

        cin.ignore();

    }


    return 0;
}

// } Driver Code Ends