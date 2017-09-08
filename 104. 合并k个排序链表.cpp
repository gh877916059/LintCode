class Solution 
{  
public:  
    struct cmp 
    {
        bool operator () (ListNode *a, ListNode *b) 
        {
            return a->val > b->val;
        }
    };
    ListNode *mergeKLists(vector<ListNode *> &lists) 
    {  
        priority_queue<ListNode*, vector<ListNode*>, cmp> q;
        for (int i = 0; i < lists.size(); ++i) 
        {
            if (lists[i]) 
                q.push(lists[i]);
        }
        ListNode *head = NULL, *pre = NULL, *tmp = NULL;
        while (!q.empty()) 
        {
            tmp = q.top();
            q.pop();
            if (!pre) 
                head = tmp;
            else 
                pre->next = tmp;
            pre = tmp;
            if (tmp->next) 
                q.push(tmp->next);
        }
        return head;
    }  
};  
