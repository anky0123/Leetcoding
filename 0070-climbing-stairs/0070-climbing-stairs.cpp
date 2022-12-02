class Solution {
public:
    int climbStairs(int n) {
    int sl = 1;
    int l = 2;
    for(int i=2;i<n;i++)
    {
        int curr = sl+l;
        sl = l;
        l = curr;
    }
        if(n<=2) return n;
        else
    return l;
    }
};