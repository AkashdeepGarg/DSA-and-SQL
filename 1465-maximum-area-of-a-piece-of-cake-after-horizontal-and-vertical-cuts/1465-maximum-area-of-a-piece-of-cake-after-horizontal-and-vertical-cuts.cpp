class Solution {
public:
    int maxArea(int h, int w, vector<int>& horizontalCuts, vector<int>& verticalCuts) {
        int maxh = INT_MIN;
        int maxv = INT_MIN;
        int prev = 0;
        sort(verticalCuts.begin(),verticalCuts.end());
        sort(horizontalCuts.begin(),horizontalCuts.end());
        for(int i=0;i<verticalCuts.size();i++){
            int temp = verticalCuts[i] - prev;
            prev = verticalCuts[i];
            maxh = max(maxh,temp);
        }
        int temp = w - prev;
        maxh = max(maxh,temp);
        prev=0;
         for(int i=0;i<horizontalCuts.size();i++){
            int temp = horizontalCuts[i] - prev;
            prev = horizontalCuts[i];
            maxv = max(maxv,temp);
        }   
        temp = h - prev;
        maxv = max(maxv,temp);
        return (1LL*maxh*maxv) % 1000000007;
    }
};