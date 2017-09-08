class Solution 
{
public:
    ListNode *deleteDuplicates(ListNode *head) 
    {
        if(head==NULL)
            return head;
        ListNode* cur=head;
        while(cur->next!=NULL)
        {
            if(cur->val==cur->next->val)
            {
                cur->next=cur->next->next;
            }
            else
            {
                cur=cur->next;
            }
        }
        return head;
    }
};
