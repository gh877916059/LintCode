/**
 * Definition of TreeNode:
 * class TreeNode {
 * public:
 *     int val;
 *     TreeNode *left, *right;
 *     TreeNode(int val) {
 *         this->val = val;
 *         this->left = this->right = NULL;
 *     }
 * }
 */
class Solution 
{
public:
    bool isBalanced(TreeNode *root) 
    {
        if(root==NULL)
            return true;
        if(abs(getHeight(root->left)-getHeight(root->right))>1)
            return false;
        return isBalanced(root->left)&&isBalanced(root->right);
    }
    int getHeight(TreeNode *root)
    {
        if(root==NULL)
            return 0;
        return max(getHeight(root->left),getHeight(root->right))+1;
    }
};
