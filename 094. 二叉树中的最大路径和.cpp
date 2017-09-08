class Solution 
{  
public:  
    int maxPathSum(TreeNode *root) 
    {  
        int ret = INT_MIN;  
        onePath(root,ret);  
        return ret;  
    }  
    int onePath(TreeNode* root,int&ret)  
    {  
        if(root==nullptr)  
            return 0;  
        int l = onePath(root->left,ret);  
        int r = onePath(root->right,ret);  
        ret = max(ret,max(0,l)+max(0,r)+root->val);  
        return max(0,max(l,r))+root->val;  
    }  
};  
