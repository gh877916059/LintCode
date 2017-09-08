class Solution 
{
public:
    ListNode *removeElements(ListNode *head, int val) 
    {
        ListNode* tou=new ListNode(0);
        tou->next=head;
        ListNode* cur=tou;
        while(cur->next!=NULL)
        {
            if(cur->next->val==val)
                cur->next=cur->next->next;
            else
                cur=cur->next;
        }
        return tou->next;
    }
};
