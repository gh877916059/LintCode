class Solution 
{
public:
vector<int> result;
    vector<int> inorderTraversal(TreeNode *root) 
    {
        if(root==NULL)
            return result;
        inorderTraversal(root->left);
        result.push_back(root->val);
        inorderTraversal(root->right);
        return result;
    }
};
