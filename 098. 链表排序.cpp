class Solution 
{
public:
    ListNode *sortList(ListNode *head) 
    {
        if(head==NULL||head->next==NULL)
            return head;
        vector<int> list;
        ListNode* cur=head;
        while(cur!=NULL)
        {
            list.push_back(cur->val);
            cur=cur->next;
        }
        sort(list.begin(),list.end());
        cur=head;
        int index=0;
        while(cur!=NULL)
        {
            cur->val=list[index];
            index++;
            cur=cur->next;
        }
        return head;
    }
};


