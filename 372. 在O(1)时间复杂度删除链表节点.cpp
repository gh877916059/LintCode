class Solution 
{
public:
    void deleteNode(ListNode *node) 
    {
        if(node==NULL||node->next==NULL)
            return;
        ListNode *next=node->next;
        node->val=next->val;
        node->next=next->next;
        return;
    }
};
