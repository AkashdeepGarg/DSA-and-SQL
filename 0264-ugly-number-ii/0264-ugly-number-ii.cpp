class Solution {
public:
    int nthUglyNumber(int n) {
        if(n<7)
            return n;
        vector<int> v(n);
        v[0]=1;
        int p2,p3,p5;
        p2=p3=p5=0;
        for(int i=1;i<n;i++){
            v[i]=min(v[p2]*2,min(v[p3]*3,v[p5]*5));
            if(v[i]==v[p2]*2)
                p2++;
            if(v[i]==v[p3]*3)
                p3++;
            if(v[i]==v[p5]*5)
                p5++;
        }
        return v[n-1];
    }
};