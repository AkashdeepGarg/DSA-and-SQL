class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int n = strs.size();
        if(n==0) return "";
        sort(strs.begin(),strs.end());
        string ans = "";
        string a = strs[0];
        string b = strs[n-1];
        cout<<a<<b<<endl;
        for(int i=0;i<a.size();i++){
            if(a[i]==b[i]){
                ans = ans + a[i];
                cout<<ans<<endl;
            }
            else{
                break;
            }
        }
        return ans;
    }
};