class Solution 
{
public:
    bool hasCycle(ListNode *head) 
    {
        if(head==NULL)
            return head;
        ListNode* fast=head;
        ListNode* slow=head;
        while(fast!=NULL)
        {
            if(fast->next!=NULL)
                fast=fast->next->next;
            else
                fast=fast->next;
            slow=slow->next;
            if(fast==slow&&fast!=NULL)
                return true;
        }
        return false;
    }
};


