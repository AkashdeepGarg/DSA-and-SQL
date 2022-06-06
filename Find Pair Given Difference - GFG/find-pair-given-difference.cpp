// { Driver Code Starts
#include<bits/stdc++.h>
 
using namespace std; 


bool findPair(int arr[], int size, int n);

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int l,n;
        cin>>l>>n;
        int arr[l];
        for(int i=0;i<l;i++)
            cin>>arr[i];
        if(findPair(arr, l, n))
            cout<<1<<endl;
        else cout<<"-1"<<endl;
    }
    
  
    return 0;
}// } Driver Code Ends


bool findPair(int arr[], int size, int n){
    //code
    /*sort(arr, arr + size);
    int S=0;
    int E=size-1;
    while(S<E){
        if(arr[E]-arr[S]==n)
        return 1;
        else if(arr[E]-arr[S]>n){
            S++;
        }
        else if(arr[E]-arr[S]<n){
            E--;
        }
    }
    return 0;*/
    
    sort(arr, arr+size);
    int i=0, j=1;
    while(i<size && j<size)
    {
        if( (i!=j)&&((arr[j]-arr[i])==n))
            return true;
        else if((arr[j]-arr[i])>n)
            i++;
        else
            j++;
    }
    return false;
    
}