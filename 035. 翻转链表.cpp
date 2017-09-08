class Solution 
{
public:
    ListNode *reverse(ListNode *head) 
    {
        return reverse(head,NULL);
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
