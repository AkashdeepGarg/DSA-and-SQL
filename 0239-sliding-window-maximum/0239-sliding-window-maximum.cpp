class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> ans;
        deque<int> pq;
        int i=0,j=0;
        while(j<nums.size()){
            while(!pq.empty() && pq.back() < nums[j]){
                pq.pop_back();
            }
            pq.push_back(nums[j]);                
            if(j-i+1 > k){
                while(j-i+1 > k){
                    int temp = nums[i];
                    if(temp==pq.front()){
                        pq.pop_front();
                    }
                    i++;
                }
            }
            if(j-i+1 == k){
                ans.push_back(pq.front());
            }
            j++;
        }

        return ans;
    }
};