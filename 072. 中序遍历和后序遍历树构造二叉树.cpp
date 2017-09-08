class Solution 
{
public:
    TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder) 
    {
        int n = postorder.size();
        if(n==0)
            return NULL;
        if(n==1)
            return new TreeNode(inorder[0]);
        int gen = postorder[n-1];
        int i=0;
        for(;i<n;++i)
        {
            if(inorder[i]==gen)
                break;
        }
        int zuo_length = i;
        int you_length = n-1-zuo_length;
        vector<int> ino;
        for(i=0;i<zuo_length;++i)
        {
            ino.push_back(inorder[i]);
        }
        vector<int> pos;
        for(i=0;i<zuo_length;++i)
        {
            pos.push_back(postorder[i]);
        }
        TreeNode* result = new TreeNode(gen);
        result->left=buildTree(ino,pos);
        ino.clear();
        pos.clear();
        for(i=zuo_length+1;i<n;++i)
        {
            ino.push_back(inorder[i]);
        }
        for(i=zuo_length;i<n-1;++i)
        {
            pos.push_back(postorder[i]);
        }
        result->right=buildTree(ino,pos);
        return result;
    }
};
