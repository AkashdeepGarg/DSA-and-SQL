class Solution {
public:
    int maxDepth(string s) {
        stack<char> st;
        int ans = 0;
        int count=0;
        for(int i=0;i<s.length();i++){
            if(s[i]=='('){
                st.push('(');
                count++;
            }
            else if(s[i]==')'){
                if(st.top()=='('){
                    ans = max(ans,count);
                    count--;
                    st.pop();
                } 
            }
        }
        return ans;
    }
};