class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        int n = strs.size();
        unordered_map<string,vector<string>> mp;
        vector<string> temp1;

        for(int i=0;i<n;i++){
            string temp = strs[i];
            sort(temp.begin(),temp.end());
            if(mp.find(temp)!=mp.end()){
                temp1 = mp[temp];
                temp1.push_back(strs[i]);
                mp[temp] = temp1;
            }
            else{
                vector<string> p;
                p.push_back(strs[i]);
                mp[temp] = p;
            }
        }
        vector<vector<string>> ans;
        for(auto i:mp){
            ans.push_back(i.second);
        }

        return ans;
    }
};