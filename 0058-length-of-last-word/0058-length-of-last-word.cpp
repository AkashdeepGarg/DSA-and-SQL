class Solution {
public:
    int lengthOfLastWord(string s) {
        int curLen = 0;
	for (int i = s.length() - 1; i >= 0; i--) {
		if (s[i] == ' ') {
			// Answer is the first time curLen>0, 
			// for it's the first word we met in s from backward.
			if (curLen > 0)
				return curLen;
			continue;
		}
		curLen++;
	}
	return curLen;
    }
};