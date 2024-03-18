class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        sort(points.begin(),points.end());
        int ans=0;
        if(points.size()==0){
            return 0;
        }
        if(points.size()==1){
            return 1;
        }
        int i=0,j=1;
        while(j<points.size()){
            if(points[i][1] >= points[j][0]){
                if(points[i][1] > points[j][1]){
                    i=j;
                }
                j++;
            }
            else{
                i=j;
                j++;
                ans++;
            }
        }
        
        return ans+1;
    }
};