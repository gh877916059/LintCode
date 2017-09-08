class Solution 
{
public:
    bool isIdentical(TreeNode* a, TreeNode* b) 
    {
        if(a==NULL&&b==NULL)
            return true;
        if(a==NULL||b==NULL)
            return false;
        if(a->val!=b->val)
            return false;
        return isIdentical(a->right,b->right)&&isIdentical(a->left,b->left);
    }
};
