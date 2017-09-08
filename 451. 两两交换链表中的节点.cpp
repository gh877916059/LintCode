class Solution 
{
public:
    ListNode* swapPairs(ListNode* head) 
    {
        if(head==NULL)
            return head;
        ListNode* cur=head;
        ListNode* next=NULL;
        ListNode* pre=NULL;
        while(cur!=NULL)
        {
            if(cur->next!=NULL)
            {
                next=cur->next->next;
                cur->next->next=cur;
                if(pre==NULL)
                    head=cur->next;
                else
                    pre->next=cur->next;
                cur->next=next;
                pre=cur;
            }
            cur=cur->next;
        }
        return head;
    }
};
