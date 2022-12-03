class Solution {
public:
    string frequencySort(string s) {
        string ans ="";
        map<char, int> mp;
        for(int i=0;i<s.size();i++)
        {
            mp[s[i]]++;
        }
        priority_queue<pair<int, char>> pq;
            for(auto [x, y] : mp)
            {
                pq.push({y,x});
            }
        while(!pq.empty())
        {
            for(int i= 0; i<pq.top().first;i++)
            {
                ans+=pq.top().second;
            }
            pq.pop();
        }
        return ans;
    }
};