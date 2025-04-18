class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        unordered_map<int,int> mp;
        for(int i=0;i<nums.size();i++){
            mp[nums[i]]++;
        }

        for(auto i:mp){
            pq.push({i.second,i.first});
            if (pq.size() > k) {
            pq.pop();
            }
        }

        vector<int> result;
        while(pq.size()!=0){
            result.push_back(pq.top().second);
            pq.pop();
        }

        return result;
    }
};