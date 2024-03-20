class Solution {
public:
    int reverse(int x) {
        long long int y = 0;
        int rem;
        while(x!=0){
            rem = x%10;
            y = y*10 + rem;
            x = x/10;
        }
        if(y>INT_MAX or y<INT_MIN){
            return 0;
        }

        return y;
    }
};