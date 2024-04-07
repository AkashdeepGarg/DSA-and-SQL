class Solution {
public:
    bool checkValidString(string s) {
        stack<int> star;
        stack<int> bracket;
        for(int i=0;i<s.length();i++){
            if(s[i]=='*'){
                star.push(i);
            }
            else if(s[i]=='('){
                bracket.push(i);
            }
            else{
                if(bracket.size()==0 and star.size()==0){
                    return false;
                }
                if(bracket.size()!=0){
                    bracket.pop();
                }
                else if(star.size()!=0){
                    star.pop();
                }
            }
        }
        while(bracket.size()!=0){
            if(star.size()==0 || bracket.top()>star.top()){
                return false;
            }
            if(star.size()!=0){
                star.pop();
                bracket.pop();
            }
        }
        
        return true;
    }
};