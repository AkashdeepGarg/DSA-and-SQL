class Solution {
public:
    bool isPalindrome(int x) {
        
        if(x>0 || x==0){
            int n, remainder;
            double rev=0;
            n=x;
            while(n!=0) {
                remainder = n % 10;
                rev = rev * 10 + remainder;
                n /= 10;
            }
            if(rev==x)
                return true;
        }
        return false;
    }
};