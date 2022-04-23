class Solution {
public:
    unordered_map<string, string> mp;
    int n=0;
    string ans = "http://tinyurl.com/";
    // Encodes a URL to a shortened URL.
    string encode(string longUrl) {
        int i=longUrl.length();
        i = i+n;
        n++;
        ans += to_string(n);
        mp[ans]=longUrl;
        return ans;
        
    }

    // Decodes a shortened URL to its original URL.
    string decode(string shortUrl) {
        return mp[ans];
    }
};

// Your Solution object will be instantiated and called as such:
// Solution solution;
// solution.decode(solution.encode(url));