class Solution 
{
public:
    vector<string> result;
    string cur;
    string IntToStr(int a)
    {
        stringstream ss;
        ss<<a;
        return ss.str();
    }
    vector<string> binaryTreePaths(TreeNode* root) 
    {
        if(root==NULL)
            return result;
        diGui(root);
        return result;
    }
    void diGui(TreeNode* root)
    {
        cur+=(IntToStr(root->val)+"->");
        string temp=cur;
        if(root->left!=NULL)
            diGui(root->left);
        cur=temp;
        if(root->right!=NULL)
            diGui(root->right);
        if(root->right==NULL&&root->left==NULL)
        {
            cur=cur.substr(0,cur.length()-2);
            result.push_back(cur);
        }
    }
};
