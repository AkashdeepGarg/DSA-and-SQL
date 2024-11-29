class Solution {
public:
    bool isValid(string s) {
        int n = s.length();
        stack<char> st;
        for(int i=0;i<n;i++){
            if(s[i]=='(' or s[i]=='{' or s[i]=='['){
                st.push(s[i]);
            }
            else if(s[i]==')'){
                if(st.size()>0 and st.top()=='('){
                    st.pop();
                }
                else{
                    return false;
                }
            }
            else if(s[i]=='}'){
                if(st.size()>0 and st.top()=='{'){
                    st.pop();
                }
                else{
                    return false;
                }
            }
            else if(s[i]==']'){
                if(st.size()>0 and st.top()=='['){
                    st.pop();
                }
                else{
                    return false;
                }
            }
        }
        
        if(st.size()!=0){
            return false;
        }
        
        return true;
    }
};