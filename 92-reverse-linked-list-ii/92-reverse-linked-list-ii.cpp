/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    pair<ListNode*,ListNode*> reverse(ListNode* head, int count)
{
    ListNode *prev = NULL;
    ListNode *curr = head;
    ListNode *temp = curr->next;
    while (count > 0)
    {
        --count;
        temp = curr->next;
        curr->next = prev;
        prev = curr;
        curr = temp;
    }
    return {prev, temp};
}

ListNode* reverseBetween(ListNode* head, int left, int right)
{
    if (head == NULL || head->next == NULL || left == right)
        return head;
    ListNode *leftNode = head;
    ListNode *beforeLeftNode = NULL;
    for (int i=1; i < left; ++i)
    {
        beforeLeftNode = leftNode;
        leftNode = leftNode->next;
    }
    auto [rightNode, afterRightNode] = reverse(leftNode, right-left+1);
    if (beforeLeftNode != NULL)
        beforeLeftNode->next = rightNode;
    else
        head = rightNode;
    leftNode->next = afterRightNode;
    return head;
}

};