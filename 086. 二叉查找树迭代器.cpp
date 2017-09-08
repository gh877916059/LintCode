class BSTIterator 
{
public:
stack<TreeNode *> mins;
    BSTIterator(TreeNode *root) 
    {
        while (root != NULL) 
        {
            mins.push(root);
            root = root->left;
        }
    }
    bool hasNext() 
    {
        return !mins.empty();
    }
    TreeNode* next() 
    {
        TreeNode *tmp = mins.top();
        mins.pop();
        TreeNode *ret = tmp;
        tmp = tmp->right;
        while (tmp != NULL) 
        { 
            mins.push(tmp);
            tmp = tmp->left;
        }
        return ret;
    }
};
