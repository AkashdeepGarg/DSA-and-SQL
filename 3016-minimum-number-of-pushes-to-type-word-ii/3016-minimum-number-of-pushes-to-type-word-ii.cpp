class Solution {
public:
    int minimumPushes(string word) {
        unordered_map<char,int> mp;
        int ans=0;
        for(int i=0;i<word.length();i++){
            mp[word[i]]++;
        }
        if(mp.size()<=8){
            return word.length();
        }
        
        vector<int> v;
        for(auto x:mp){
            v.push_back(x.second);
        }
        sort(v.begin(),v.end());
        reverse(v.begin(),v.end());
        int counter=1;
        for(int i=0;i<v.size();i++){
            int temp = counter/8;
            if(counter%8!=0){
                temp=temp+1;
            }
            ans = ans+v[i]*temp;
            counter++;
        }
        
        return ans;
    }
};