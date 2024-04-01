class Solution {
public:
    int strStr(string haystack, string needle) {
        int n=haystack.length();
        int m=needle.length();
        if(m>n or m==0){
            return -1;
        }
        int counter=0;
        int start=0,end=0;
        while(end<n and counter < m){
            if(haystack[end]==needle[counter]){
                end++;
                counter++;
                if(counter==m){
                    return start;
                }
            }
            else{
                counter=0;
                start++;
                end=start;
            }
        }
        return -1;
    }
};