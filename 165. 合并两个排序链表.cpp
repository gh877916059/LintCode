class Solution 
{
public:
    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) 
    {
        ListNode* wow = new ListNode(0);
        wow->next=NULL;
        ListNode* result = wow;
        while(l1!=NULL&&l2!=NULL)
        {
            if(l1->val<l2->val)
            {
                wow->next=l1;
                l1=l1->next;
            }
            else
            {
                wow->next=l2;
                l2=l2->next;
            }
            wow=wow->next;
        }
        while(l1!=NULL)
        {
            wow->next=l1;
            l1=l1->next;
            wow=wow->next;
        }
        while(l2!=NULL)
        {
            wow->next=l2;
            l2=l2->next;
            wow=wow->next;
        }
        return result->next;
    }
};
