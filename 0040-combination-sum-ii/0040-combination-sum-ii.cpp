class Solution {
public:
    void solve(int ind,int target, vector<int>& arr, vector<vector<int>>& ans, vector<int> &ds){
        if(ind == arr.size()){
            if(target==0){
                ans.push_back(ds);
            }
            return;
        }
        if(target==0){
            ans.push_back(ds);
            return;
        }

        for(int i=ind;i<arr.size();i++){
            if(i!=ind and arr[i]==arr[i-1]) continue;
            if(target >= arr[ind] ){
                ds.push_back(arr[i]);
                solve(i+1,target-arr[i],arr,ans,ds);
                ds.pop_back();
            }

        }
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());

        vector<vector<int>> ans;
        vector<int> ds;
        solve(0,target,candidates,ans,ds);

        return ans;
    }
};