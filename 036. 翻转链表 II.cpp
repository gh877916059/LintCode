class Solution 
{
public:
    ListNode *reverseBetween(ListNode *head, int m, int n) 
    {
        if(head==NULL||head->next==NULL)
            return head;
        ListNode* new_begin=NULL;
        ListNode* new_end=NULL;
        int counter=1;
        ListNode* pre=head;
        ListNode* cur=head->next;
        ListNode* next=NULL;
        ListNode* m_qian=NULL;
        while(cur!=NULL)
        {
            if(counter>=m&&counter<n)
            {
                next=cur->next;
                cur->next=pre;
                pre=cur;
                cur=next;
            }
            else
            {
                if(counter==m-1)
                {
                    m_qian=pre;
                }
                else if(counter==n)
                {
                    if(m_qian==NULL)
                    {
                        head->next=cur;
                        head=pre;
                    }
                    else
                    {
                        m_qian->next->next=cur;
                        m_qian->next=pre;
                    }
                }
                pre=cur;
                cur=cur->next;
            }
            ++counter;
        }
        if(counter<=n)
        {
            m_qian->next->next=NULL;
            m_qian->next=pre;
        }
        return head;
    }
};
