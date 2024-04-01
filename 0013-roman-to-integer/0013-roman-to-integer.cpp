class Solution {
public:
    int romanToInt(string s) {
        int result=0;
        map<char,int> mp;
        mp['I']=1;
        mp['V']=5;
        mp['X']=10;
        mp['L']=50;
        mp['C']=100;
        mp['D']=500;
        mp['M']=1000;
        int i=s.length()-1;
        while(i>=1){
            if(mp[s[i-1]]<mp[s[i]]){
                result+=(mp[s[i]]-mp[s[i-1]]);
                cout<<result<<" From 1"<<endl;
                i=i-2;
            }
            else{
                result += mp[s[i]];
                cout<<result<<" From2"<<endl;
                i--;
            }
        }
        if(i<0){
            return result;
        }
        result += mp[s[0]];
        return result;
    }
};