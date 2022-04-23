class Solution {
public:
    int hammingWeight(uint32_t n) {
        unsigned mask = 1;
        short counter = 0;
        for(int i=0;i<32;++i){
            if(mask<<i & n) 
                counter++;
        }
        return counter;
    }
};