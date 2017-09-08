class Solution 
{
public:
    bool isSubtree(TreeNode *T1, TreeNode *T2) 
    {
        if(T2==NULL)
            return true;
        return subTree(T1,T2);
    }
    bool subTree(TreeNode* r1,TreeNode* r2)
    {
        if(r1==NULL)
            return false;
        if(r1->val==r2->val)
        {
            if(matchTree(r1,r2))
                return true;
        }
        return (subTree(r1->left,r2)||subTree(r1->right,r2));
    }
    bool matchTree(TreeNode* r1,TreeNode* r2)
    {
        if(r2==NULL&&r1==NULL)
            return true;
        if(r1==NULL||r2==NULL)
            return false;
        if(r1->val!=r2->val)
            return false;
        return (matchTree(r1->left, r2->left) && matchTree(r1->right, r2->right));
    }
};
