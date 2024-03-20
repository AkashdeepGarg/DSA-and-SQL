class Solution {
public:
    // Using Log Properties
    //  bool isPowerOfTwo(int n) {
    //     if(n <= 0) return false;
    //     return ceil(log2(n)) == floor(log2(n));
    // }
    
    //Using bit manipulation
    bool isPowerOfTwo(int n) {
        if(n<=0) return false;
        return ((n&(n-1))==0);
    }

    // bool isPowerOfTwo(int n) {
    //     if(n==0){
    //         return false;
    //     }
    //     while(n%2==0) n/=2;
    //     return n==1;
    // }
};