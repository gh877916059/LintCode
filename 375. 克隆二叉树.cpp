class Solution 
{
public:
    TreeNode* cloneTree(TreeNode *root) 
    {
        if(root==NULL)
            return NULL;
        TreeNode* result=new TreeNode(root->val);
        result->left=cloneTree(root->left);
        result->right=cloneTree(root->right);
        return result;
    }
};
