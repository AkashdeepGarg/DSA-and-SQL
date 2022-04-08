#include <iostream>
#include <bits/stdc++.h>

using namespace std;

void frequency(int arr[],int n){
    unordered_map<int, int> mp;
    for(int i=0;i<n;i++){
        mp[arr[i]]++;
    }
    priority_queue<pair<int, int>> maxh;
    for(auto i=mp.begin();i!=mp.end();i++){
        maxh.push(make_pair(i->second, i->first));
    }
    cout<<"Answer:"<<endl;
    while(maxh.size()>0){
        cout<<maxh.top().second<<" ";
        maxh.pop();
    }
}

int main()
{
    int t;
    cout<<"Enter the number of test cases: ";
    cin>>t;
    while(t>0){
        int n;
        cout<<"Enter the length of array: ";
        cin>>n;
        int arr[n];
        cout<<"Enter the elements of the array"<<endl;
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        frequency(arr,n);
        
        t--;
    }
    

    return 0;
}
