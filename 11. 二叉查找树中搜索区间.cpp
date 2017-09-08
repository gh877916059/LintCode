class Solution 
{
public:
    vector<int> result;
    vector<int> searchRange(TreeNode* root, int k1, int k2) 
    {
        if(root==NULL)
            return result;
        if(root->val>k2)
        {
            searchRange(root->left,k1,k2);
        }
        else if(root->val<k1)
        {
            searchRange(root->right,k1,k2);
        }
        else
        {
            searchRange(root->left,k1,k2);
            result.push_back(root->val);
            searchRange(root->right,k1,k2);
        }
        return result;
    }
};
