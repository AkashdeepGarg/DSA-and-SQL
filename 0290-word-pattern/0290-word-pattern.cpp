class Solution {
public:
    bool wordPattern(string pattern, string s) {
        unordered_map<char, string> mp;
        unordered_map<string, char> mp2;
        string temp = "";
        int patternIndex = 0;
        int n = s.length(); 
        
        for (int i = 0; i <= n; ++i) { 
            if (i == n || s[i] == ' ') { 
                if (patternIndex >= pattern.length()) {
                    return false;
                }
                char currentPatternChar = pattern[patternIndex];
                
                if (mp.find(currentPatternChar) != mp.end() && mp[currentPatternChar] != temp) {
                    return false;
                }
                if (mp2.find(temp) != mp2.end() && mp2[temp] != currentPatternChar) {
                    return false;
                }
                
                mp[currentPatternChar] = temp;
                mp2[temp] = currentPatternChar;
                
                patternIndex++;
                temp = "";
            } else {
                temp += s[i];
            }
        }
        
        return patternIndex == pattern.length();
    }
};