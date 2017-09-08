class Solution 
{
public:
    ListNode *rotateRight(ListNode *head, int k) 
    {
        if(head==NULL)
            return head;
        int length =0;
        for(ListNode* cur=head;cur!=NULL;cur=cur->next)
        {
            ++length;
        }
        k%=length;
        if(k==0)
            return head;
        ListNode* hou = head;
        for(int i=0;i<k;++i)
        {
            if(hou==NULL)
                break;
            hou=hou->next;
        }
        ListNode* qian = head;
        while(hou!=NULL)
        {
            qian=qian->next;
            hou=hou->next;
        }
        if(qian!=head)
        {
            ListNode* temp=qian;
            while(temp->next!=NULL)
                temp=temp->next;
            temp->next=head;
            while(head->next!=qian)
                head=head->next;
            head->next=NULL;
        }
        return qian;
    }
};
