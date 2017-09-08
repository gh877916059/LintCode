class Solution 
{
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) 
    {
        if(headA==NULL||headB==NULL)
            return NULL;
        int len_A=0;
        int len_B=0;
        ListNode* cur=headA;
        while(cur!=NULL)
        {
            ++len_A;
            cur=cur->next;
        }
        cur=headB;
        while(cur!=NULL)
        {
            ++len_B;
            cur=cur->next;
        }
        int xian_zou=abs(len_A-len_B);
        if(len_A>len_B)
        {
            for(int i=0;i<xian_zou;++i)
                headA=headA->next;
        }
        else if(len_B>len_A)
        {
            for(int i=0;i<xian_zou;++i)
                headB=headB->next;
        }
        while(headA!=headB)
        {
            headA=headA->next;
            headB=headB->next;
        }
        return headA;
    }
};
