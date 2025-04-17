class Solution {
public:
    int shipWithinDays(vector<int>& weights, int D) {
        int left = 0;
        int right = 0;
        for(int i:weights){
            left = max(left,i);
            right+=i;
        }

        while(left<right){
            int mid = left + (right-left)/2;
            int days=1;
            int curr=0;
            for(int i=0;i<weights.size();i++){
                if(curr + weights[i] > mid){
                    days++;
                    curr=0;
                }
                curr+=weights[i];
            }
            if(days <= D){
                right = mid;
            }
            else{
                left = mid+1;
            }
        }

        return left;
    }
};