class Solution {
public:
    string reverseWords(string s) {
        stack<string> st;
        string temp="";
        for(int i=0;i<s.length();i++){
            if(s[i]!=' '){
                temp = temp + s[i];
            }
            else{
                if(temp.length()>0){
                    st.push(temp);
                }
                temp = "";
            }
        }
        if(temp.length() > 0){
            st.push(temp);
        }
        temp="";
        while(st.size()>0){
            temp = temp+st.top();
            st.pop();
            if(st.size()>0){
                temp = temp + ' ';
            }
        }
        
        return temp;
        
    }
};