// { Driver Code Starts
// driver

#include <bits/stdc++.h>
using namespace std;

/* Linked list Node */
struct Node {
    int data;
    struct Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

struct Node* buildList(int size)
{
    int val;
    cin>> val;
    
    Node* head = new Node(val);
    Node* tail = head;
    
    for(int i=0; i<size-1; i++)
    {
        cin>> val;
        tail->next = new Node(val);
        tail = tail->next;
    }
    
    return head;
}

void printList(Node* n)
{
    while(n)
    {
        cout<< n->data << " ";
        n = n->next;
    }
    cout<< endl;
}


 // } Driver Code Ends
/* node for linked list:

struct Node {
    int data;
    struct Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

*/

class Solution
{
    public:
    //Function to add two numbers represented by linked list.
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
    
    struct Node* addTwoLists(struct Node* first, struct Node* second)
    {
        // code here
        Node* temp1= reverseList(first);
        Node* temp2= reverseList(second);
        Node* head = NULL;
        Node* curr=NULL;
        Node* temp;
        int carry=0;
        while(temp1!=NULL || temp2!=NULL){
            int sum = (temp1?temp1->data:0) + (temp2?temp2->data:0) + carry;
            carry=(sum>=10)?1:0;
                sum =sum%10;
                temp = new Node(sum);
            if(head==NULL){
                head=temp;
            }
            else{
                curr->next=temp;
            }
            curr=temp;
            if(temp1){
            temp1=temp1->next;
            }
            if(temp2){
            temp2=temp2->next;
            }
        }
        if(carry){
            temp = new Node(1);
            curr->next=temp;
            curr=temp;
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
        int n, m;
        
        cin>>n;
        Node* first = buildList(n);
        
        cin>>m;
        Node* second = buildList(m);
        Solution ob;
        Node* res = ob.addTwoLists(first,second);
        printList(res);
    }
    return 0;
}
  // } Driver Code Ends