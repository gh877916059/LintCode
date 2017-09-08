class Solution 
{
public:
    void invertBinaryTree(TreeNode *root) 
    {
        stack<TreeNode*> stack;
        TreeNode* p=root;
        while(p!=NULL||!stack.empty())
        {
            while(p!=NULL)
            {
                TreeNode* temp=p->left;
                p->left=p->right;
                p->right=temp;
                stack.push(p);
                p=p->left;
            }
            if(!stack.empty())
            {
                p=stack.top();
                stack.pop();
                p=p->right;
            }
        }
    }
};
