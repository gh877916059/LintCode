class Solution 
{
public:
    ListNode *nthToLast(ListNode *head, int n) 
    {
        if(head==NULL||head->next==NULL)
            return head;
        ListNode* hou=head;
        ListNode* qian=head;
        for(int i=0;i<n;++i)
        {
            if(hou==NULL)
                break;
            hou=hou->next;
        }
        while(hou!=NULL)
        {
            qian=qian->next;
            hou=hou->next;
        }
        return qian;
    }
};
