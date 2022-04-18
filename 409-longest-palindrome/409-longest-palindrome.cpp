class Solution {
public:   
    int longestPalindrome(string s) {
       unordered_map<char, int> counts;
        for(char c:s)
            counts[c]++;
        int result=0;
        bool found = false;
        for(auto& c:counts){
            if(c.second%2==0)
                result+=c.second;
            else{
                found = true;
                result+=c.second-1;
            }
            
        }
        if(found)
                result++;
        return result;
    }
};