class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int length = 0;
        int l=0,r=0;
        unordered_map<char, int> mp;
     while(r<s.size())
     {
         if(mp.count(s[r])) l= max(l, 1 + mp[s[r]]);
         mp[s[r]] = r;
         r++;
         length = max(length, r-l);
     }
        return length;
    }
};