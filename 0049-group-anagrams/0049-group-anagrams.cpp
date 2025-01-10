class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        sort(strs.begin(),strs.end());
        vector<string> temp = strs;
        for(int i=0;i<strs.size();i++){
            string t = strs[i];
            sort(t.begin(),t.end());
            strs[i] = t;
        }

        unordered_map<string,vector<string>> mp;
        for(int i=0;i<strs.size();i++){
            if(mp.find(strs[i])!=mp.end()){
                mp[strs[i]].push_back(temp[i]);
            }
            else{
                vector<string> t2;
                t2.push_back(temp[i]);
                mp[strs[i]] = t2;
            }
        }

        vector<vector<string>> ans;
        for(auto s: mp){
            ans.push_back(s.second);
        }

        return ans;
    }
};