class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        vector<vector<int>> ans;
        if(points.size()==0){
            return ans;
        }
        priority_queue<pair<int,pair<int,int>>> pq;
        for(int i=0;i<points.size();i++){
            int first = points[i][0];
            int second = points[i][1];
            int d = pow(first,2) + pow(second,2);
            pq.push(make_pair(d,make_pair(first,second)));
            if(pq.size() > k){
                pq.pop();
            }
        }
        while(pq.size()>0){
            pair<int,pair<int,int>> temp = pq.top();
            pq.pop();
            vector<int> t;
            t.push_back(temp.second.first);
            t.push_back(temp.second.second);
            ans.push_back(t);
        }
        
        return ans;
    }
};