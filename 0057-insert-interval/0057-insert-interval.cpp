class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        int flag=0;
        for(int i=0;i<intervals.size();i++){
            if(newInterval[1]<intervals[i][0]){
                intervals.insert(intervals.begin()+i,newInterval);
                flag=1;
                break;
            }
            if(newInterval[0] < intervals[i][1]){
                intervals[i][0] = min(newInterval[0],intervals[i][0]);
                intervals[i][1] = max(newInterval[1],intervals[i][1]);
                flag=1;
                break;
            }
        }
        if(flag==0){
            intervals.push_back(newInterval);
        }
        
        // for(auto x:intervals){
        //     cout<<x[0]<<" "<<x[1]<<endl;
        // }
        // cout<<"After"<<endl;
        
        int i=0;
        int j=1;
        int n=intervals.size();
        while(j<n){
            if(intervals[i][1] >= intervals[j][0]){
                intervals[i][0] = min(intervals[i][0],intervals[j][0]);
                intervals[i][1] = max(intervals[i][1],intervals[j][1]);
                n--;
                intervals.erase(intervals.begin()+j);
            }
            else{
                j++;
                i++;
            }
        }
        // for(auto x:intervals){
        //     cout<<x[0]<<" "<<x[1]<<endl;
        // }
        
        return intervals;
    }
};