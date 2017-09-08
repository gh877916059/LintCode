class Solution 
{
public:
    ListNode* swapNodes(ListNode* head, int v1, int v2) 
    {
        ListNode *dummy = new ListNode(-1);
        dummy->next = head;
        ListNode *pre = dummy, *cur = dummy, *p1 = NULL, *p2 = NULL;
        while (cur->next) 
        {
            if (cur->next->val == v1 || cur->next->val == v2) 
            {
                if (!p1) 
                {
                    p1 = cur->next;
                    pre = cur;
                } 
                else 
                {
                    ListNode *t = cur->next->next;
                    p2 = cur->next;
                    pre->next = p2;
                    if (cur == p1) 
                    {
                        p2->next = p1;
                        p1->next = t;
                    } 
                    else 
                    {
                        p2->next = p1->next;
                        cur->next = p1;
                        p1->next = t;
                    }
                    return dummy->next;
                }
            }
            cur = cur->next;
        }
        return dummy->next;
    }
};
