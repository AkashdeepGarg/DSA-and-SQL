class Solution {
public:
    int numberOfSubstrings(string s) {
        int n = s.length();
        int count=0;int j=0;
        vector<int> freq(3,-1);
        while(j<n){
            freq[s[j]-'a']=j;
            if(freq[0]!=-1 && freq[1]!=-1 && freq[2]!=-1){
                count = count + (1 + min({freq[0], freq[1],freq[2]}));
            }
            j++;
        }

        return count;
    }
};