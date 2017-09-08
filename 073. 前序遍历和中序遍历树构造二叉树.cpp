class Solution 
{
public:
    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) 
    {
        TreeNode* fan_hui=NULL;
        if(preorder.size()==0)
            return fan_hui;
        int gen=preorder[0];
        int i=0;
        for(;i<(int)inorder.size();++i)
        {
            if(inorder[i]==gen)
                break;
        }
        fan_hui=new TreeNode(gen);
        vector<int> pre;
        vector<int> ino;
        int pre_index=1;
        for(int j=0;j<i;++j,++pre_index)
        {
            ino.push_back(inorder[j]);
            pre.push_back(preorder[pre_index]);
        }
        fan_hui->left=buildTree(pre,ino);
        pre.clear();
        ino.clear();
        for(int j=i+1;j<(int)inorder.size();++j,++pre_index)
        {
            ino.push_back(inorder[j]);
            pre.push_back(preorder[pre_index]);
        }
        fan_hui->right=buildTree(pre,ino);
        return fan_hui;
    }
};
