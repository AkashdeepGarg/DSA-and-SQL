class Solution {
public:
    int maxArea(vector<int>& height) {
        int l=0,r=(height.size()-1),maxs=0;
        while(l<r){
            int l1=height[l];
            int r1=height[r];
            int y = min(l1,r1);
            maxs = max(y*(r-l),maxs);
            if(l1<r1)
                l++;
            else
                r--;
        }
        
        return maxs;
    }
};