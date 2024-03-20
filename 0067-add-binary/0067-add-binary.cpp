class Solution {
public:
    
    // Converting to decimal and then adding and converting back to binary
    // int convertToDecimal(string x){
    //     reverse(x.begin(),x.end());
    //     long long int ans=0;
    //     for(int i=0;i<x.length();i++){
    //         if(x[i]=='1')
    //         ans+=pow(2,i);
    //     }
    //     return ans;
    // }
    // string convertToBinary(int x){
    //     string temp;
    //     int rem;
    //     while(x!=0){
    //         rem = x%2;
    //         x=x/2;
    //         if(rem==1){
    //             temp.push_back('1');
    //         }
    //         else{
    //             temp.push_back('0');
    //         }
    //     }
    //     if(temp==""){
    //         temp.push_back('0');
    //     }
    //     reverse(temp.begin(),temp.end());
    //     return temp;
    // }
    // string addBinary(string a, string b) {
    //     int temp = convertToDecimal(a) + convertToDecimal(b);
    //     cout<<temp;
    //     return convertToBinary(temp);
    // }
    
    string addBinary(string a, string b) {
    string ans;
    int carry = 0;
    int i = a.length() - 1;
    int j = b.length() - 1;

    while (i >= 0 || j >= 0 || carry) {
      if (i >= 0)
        carry += a[i--] - '0';
      if (j >= 0)
        carry += b[j--] - '0';
      ans += carry % 2 + '0';
      carry /= 2;
    }

    reverse(begin(ans), end(ans));
    return ans;
  }
};