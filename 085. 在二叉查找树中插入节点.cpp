class Solution 
{
public:
    TreeNode* insertNode(TreeNode* root, TreeNode* node) 
    {
        if(root==NULL)
        {
            root=node;
            return root;
        }
        if(node->val<root->val)
        {
            root->left=insertNode(root->left,node);
        }
        if(node->val>root->val)
        {
            root->right=insertNode(root->right,node);
        }
        return root;
    }
};
