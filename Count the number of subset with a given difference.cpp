//Akashdeep

#include <iostream>
#include<vector>
using namespace std;

int noofsubset(vector<int>& arr, int sum){
    int n = arr.size();
    int t[n+1][sum+1];
    for(int i=0;i<n+1;i++){
        for(int j=0;j<sum+1;j++){
            if(i==0)
            t[i][j]=0;
            if(j==0)
            t[i][j]=1;
        }
    }
    for(int i=1;i<n+1;i++){
        for(int j=1;j<sum+1;j++){
            if(arr[i-1]<=j){
                t[i][j] = t[i-1][j] + t[i-1][j-arr[i-1]];
            }
            else{
                t[i][j] = t[i-1][j];
            }
        }
    }
    return t[n][sum];
}

int main()
{
    vector<int> arr;
    int n;
    std::cout << "Enter the number of elements: " << std::endl;
    std::cin >> n;
    int diff;
    std::cout << "Enter the Difference: " << std::endl;
    std::cin >> diff;
    int a;
    std::cout << "Enter the elements: " << std::endl;
    for(int i=0;i<n;i++){
        std::cin >> a;
        arr.push_back(a);
    }
    int sum=0;
    for(int i=0;i<n;i++){
        sum+=arr[i];
    }
    sum = sum-diff;
    if(sum%2!=0){
        std::cout << "Answer is: " << std::endl;
        std::cout << 0 << std::endl;
    }
    else{
        sum = sum/(int)2;
        std::cout << "Answer is: " << std::endl;
        std::cout << noofsubset(arr,sum) << std::endl;
    }

    return 0;
}
