class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<int> v;
        if(k>nums.size()){
            return v;
        }
        unordered_map<int,int> mp;
        for(int i=0;i<nums.size();i++){
            mp[nums[i]]++;
        }
        priority_queue<pair<int,int>> pq;
        for(auto p : mp){
            pq.push({p.second,p.first});
        }
        while(k){
            auto temp = pq.top();
            v.push_back(temp.second);
            pq.pop();
            k--;
        }
        
        return v;
    }
};