class Solution
{
public:
    ListNode * deleteDuplicates(ListNode *head) 
    {
        if(head==NULL||head->next==NULL)
            return head;
        ListNode* new_begin=NULL;
        ListNode* new_end=NULL;
        ListNode* qian=head;
        ListNode* hou=head;
        while(qian!=NULL)
        {
            while(hou->next!=NULL&&hou->next->val==qian->val)
                hou=hou->next;
            if(qian==hou)
            {
                if(new_begin==NULL)
                {
                    new_begin=qian;
                    new_end=qian;
                }
                else
                {
                    new_end->next=qian;
                    new_end=new_end->next;
                }
            }
            qian=hou->next;
            hou=hou->next;
        }
        if(new_end!=NULL)
            new_end->next=NULL;
        return new_begin;
    }
};
