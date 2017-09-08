class Solution 
{
public:
    bool isPalindrome(ListNode* head) 
    {
        if(head==NULL||head->next==NULL)
            return true;
        ListNode* slow=head;
        ListNode* fast=head;
        while(fast!=NULL&&fast->next!=NULL)
        {
            slow=slow->next;
            fast=fast->next->next;
        }
        if(fast!=NULL)
        {
            slow->next=reverse(slow->next,NULL);
            slow=slow->next;
        }
        else
        {
            slow=reverse(slow,NULL);
        }
        while(slow!=NULL)
        {
            if(head->val!=slow->val)
                return false;
            slow=slow->next;
            head=head->next;
        }
        return true;
    }
    ListNode* reverse(ListNode* head, ListNode* tail) 
    {
        ListNode *pre = tail;
        while (head != tail) 
        {
            ListNode *t = head->next;
            head->next = pre;
            pre = head;
            head = t;
        }
        return pre;
    }
};
