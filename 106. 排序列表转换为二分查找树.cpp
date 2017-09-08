class Solution {
public:
    TreeNode *sortedListToBST(ListNode *head) 
    {
        if(head==NULL)  
            return NULL;  
        int len = 0;  
        ListNode*temp = head;  
        while(temp){len++;temp = temp->next;};  
        if(len==1)  
        {  
            return new TreeNode(head->val);  
        }  
        else if(len==2)  
        {  
            TreeNode*root = new TreeNode(head->val);  
            root->right = new TreeNode(head->next->val);  
            return root;  
        }  
        else  
        {  
            len/=2;  
            temp = head;  
            int cnt = 0;  
            while(cnt<len)  
            {  
                temp = temp->next;  
                cnt++;  
            }  
            ListNode*pre = head;  
            while(pre->next!=temp)  
                pre = pre->next;  
            pre->next = nullptr;  
            TreeNode*root = new TreeNode(temp->val);  
            root->left = sortedListToBST(head);  
            root->right = sortedListToBST(temp->next);  
            return root;  
        }  
    }
};


