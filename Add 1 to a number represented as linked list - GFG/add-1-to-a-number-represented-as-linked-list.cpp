// { Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h> 
using namespace std; 

struct Node
{
    int data;
    struct Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
};

void printList(Node* node) 
{ 
    while (node != NULL) { 
        cout << node->data; 
        node = node->next; 
    }  
    cout<<"\n";
} 


 // } Driver Code Ends
//User function template for C++

/* 

struct Node
{
    int data;
    struct Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
};

*/

class Solution
{
    public:
    
    struct Node* reverseList(struct Node *head)
    {
        // code here
        // return head of reversed list
        Node * curr=head,*prev=NULL,*nextPtr;
        
        while(curr!=NULL){
            nextPtr=curr->next;
            curr->next=prev;
            prev=curr;
            curr=nextPtr;
        }
        return prev;
    }
    
    Node* addOne(Node *head) 
    {
        // Your Code here
        // return head of list after adding one
        head = reverseList(head);
        bool flag=true;
        Node* temp = head;
        while(temp!=NULL && flag==true){
            if(temp->next==NULL && temp->data==9){
                temp->data=1;
                Node* n = new Node(0);
                n->next=head;
                head=n;
                temp=temp->next;
            }
            else if(temp->data==9){
                temp->data=0;
                temp=temp->next;
            }
            else{
                temp->data=temp->data+1;
                flag=false;
                temp = temp->next;
            }
        }
        
        return reverseList(head);
    }
};

// { Driver Code Starts.

int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        string s;
        cin>>s;
        
        Node* head = new Node( s[0]-'0' );
        Node* tail = head;
        for(int i=1; i<s.size(); i++)
        {
            tail->next = new Node( s[i]-'0' );
            tail = tail->next;
        }
        Solution ob;
        head = ob.addOne(head);
        printList(head); 
    }
    return 0; 
} 
  // } Driver Code Ends