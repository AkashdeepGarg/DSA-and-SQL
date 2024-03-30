class Solution {
public:
    int longestSubstring(string s, int k) {
        if(k<=1){
            return s.length();
        }
        if(k>s.length() or s.length()==0){
            return 0;
        }
        int n = s.size();
        return longestSubstringUtil(s, 0, n, k);
    }
    int longestSubstringUtil(string &s, int start, int end, int k) {
        if (end < k) return 0;
        map<char,int> mp;
        for (int i = start; i < end; i++)
            mp[s[i]]++;
        for (int mid = start; mid < end; mid++) {
            if (mp[s[mid]] >= k) continue;
            int midNext = mid + 1;
            while (midNext < end && mp[s[midNext]] < k) midNext++;
            return max(longestSubstringUtil(s, start, mid, k),
                    longestSubstringUtil(s, midNext, end, k));
        }
        return (end - start);
    }
};