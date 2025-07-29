class Solution {
public:
    int pal(string &st, int s, int e) {
        int c = 0;
        while (s >= 0 && e < st.size() && st[s] == st[e]) {
            c++;
            s--; 
            e++;
        }
        return c;
    }

    int countSubstrings(string s) {
        int res = 0;
        for (int i = 0; i < s.size(); i++) {
            res += pal(s, i, i);     // Odd-length palindromes
            res += pal(s, i, i + 1); // Even-length palindromes
        }
        return res;
    }
};