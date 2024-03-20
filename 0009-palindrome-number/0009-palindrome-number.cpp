class Solution {
public:
    bool isPalindrome(int x) {
        if(x==0){
            return true;
        }
        if(x<0){
            return false;
        }
        int t =x;
        long long int y = 0;
        while(t>0){
            int rem = t%10;
            y = y*10 + rem;
            t = t/10;
        }
        if(x==y){
            return true;
        }
        return false;
    }
};