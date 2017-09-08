class Solution 
{
public:
    bool isValidBST(TreeNode *root) 
    {
        if(root==NULL)
            return true;
        if(wow(root->left,root->val,false)&&wow(root->right,root->val,true))
        {
            return isValidBST(root->left)&&isValidBST(root->right);
        }
        return false;
    }
    bool wow(TreeNode* root,int biao_zhun,bool is_da_yu)
    {
        if(root==NULL)
            return true;
        if(is_da_yu)
        {
            if(root->val<=biao_zhun)
                return false;
        }
        else
        {
            if(root->val>=biao_zhun)
                return false;
        }
        return wow(root->left,biao_zhun,is_da_yu)&&wow(root->right,biao_zhun,is_da_yu);
    }
};
