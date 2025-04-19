class Solution {
public:
    string minWindow(string s, string t) {
        int i=0;int j=0;
        int ind=-1;
        int len=INT_MAX;
        int count=0;
        unordered_map<char,int> mp;
        for(char k:t){
            mp[k]++;
        }
        while(j<s.length()){
            if(mp[s[j]]>0){
                count++;
            }
            mp[s[j]]--;
            while(count==t.length()){
                if(len >= j-i+1){
                    len = j-i+1;
                    ind = i;
                }
                mp[s[i]]++;
                if(mp[s[i]]>0){
                    count--;
                }
                i++;
            }
            
            j++;
        }

        return ind==-1 ? "" : s.substr(ind,len);
    }
};