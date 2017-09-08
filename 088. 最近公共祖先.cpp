class Solution
{
public:
	TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *A, TreeNode *B)
	{
		vector<TreeNode*> APath;
		vector<TreeNode*> BPath;
		vector<TreeNode*> cur;
		dfs(cur, root, A, B, APath, BPath);
		TreeNode* ret = root;
		for (int i = 0; i<min(APath.size(), BPath.size()); i++)
		{
			if (APath[i] == BPath[i])
			{
				ret = APath[i];
			}
			else
				break;
		}
		return ret;
	}
	void dfs(vector<TreeNode*> cur, TreeNode*root, TreeNode *A, TreeNode *B, vector<TreeNode*> &APath, vector<TreeNode*> &BPath)
	{
		cur.push_back(root);
		if (root == A)
			APath = cur;
		if (root == B)
			BPath = cur;
		if (root->left)
			dfs(cur, root->left, A, B, APath, BPath);
		if (root->right)
			dfs(cur, root->right, A, B, APath, BPath);
	}
};
