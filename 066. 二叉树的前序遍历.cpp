class Solution 
{
public:
vector<int> result;
    vector<int> preorderTraversal(TreeNode *root) 
    {
        wow(root);
        return result;
    }
    void wow(TreeNode *root)
    {
        if(root!=NULL)
            result.push_back(root->val);
        else
            return;
        wow(root->left);
        wow(root->right);
    }
};
