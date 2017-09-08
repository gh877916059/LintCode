class Solution 
{
public:
    ListNode *removeNthFromEnd(ListNode *head, int n) 
    {
        if(head==NULL)
            return head;
        ListNode *hou = new ListNode(0);
        ListNode *qian =hou;
        
        hou->next=head;
        for(int i=1;i<n;++i)
        {
            if(hou->next==NULL)
                break;
            hou=hou->next;
        }
        while(hou->next->next!=NULL)
        {
            qian=qian->next;
            hou=hou->next;
        }
        if(qian->next==head)
            head=head->next;
        qian->next=qian->next->next;
        return head;
    }
};


