class Solution 
{
public:
    TreeNode* removeNode(TreeNode* root, int value) 
    {
        if(root==NULL)
            return NULL;
        if(value<root->val)  
            root->left = removeNode(root->left,value);  
        else if(value>root->val)
            root->right = removeNode(root->right,value);  
        else
        {  
            if(root->right==NULL&&root->left==NULL)
                return NULL;
            else if(root->right!=NULL&&root->left!=NULL)
            {
                root->val = findMin(root->right);  
                root->right = removeNode(root->right,root->val);
            }
            else
            {
                root = (root->left != NULL)?root->left:root->right;
            }
        }  
        return root;
    }
private:
    int findMin(TreeNode* root)
    {
        if(root->left!=NULL)
            return findMin(root->left);
        else
            return root->val;
    }
};
