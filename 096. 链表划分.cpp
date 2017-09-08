class Solution 
{
public:
    ListNode *partition(ListNode *head, int x) 
    {
        if(head==NULL||head->next==NULL)
            return head;
        ListNode* qian_begin=NULL;
        ListNode* qian_end=NULL;
        ListNode* hou_begin=NULL;
        ListNode* hou_end=NULL;
        ListNode* cur=head;
        while(cur!=NULL)
        {
            if(cur->val<x)
            {
                if(qian_begin==NULL)
                {
                    qian_begin=cur;
                    qian_end=cur;
                }
                else
                {
                    qian_end->next=cur;
                    qian_end=qian_end->next;
                }
            }
            else
            {
                if(hou_begin==NULL)
                {
                    hou_begin=cur;
                    hou_end=cur;
                }
                else
                {
                    hou_end->next=cur;
                    hou_end=hou_end->next;
                }
            }
            cur=cur->next;
        }
        if(qian_end!=NULL)
            qian_end->next=NULL;
        if(hou_end!=NULL)
            hou_end->next=NULL;
        if(qian_end!=NULL)
        {
            qian_end->next=hou_begin;
            return qian_begin;
        }
        else
            return hou_begin;
    }
};


