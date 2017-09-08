class Solution
{
public:
	unordered_map<TreeNode*, int> M;
	int houseRobber3(TreeNode* root)
	{
		if (root == NULL)
			return 0;
		if (M.find(root) != M.end())
			return M[root];
		int rob = root->val;
		if (root->left != NULL)
		{
			rob += houseRobber3(root->left->left);
			rob += houseRobber3(root->left->right);
		}
		if (root->right != NULL)
		{
			rob += houseRobber3(root->right->left);
			rob += houseRobber3(root->right->right);
		}
		int noRob = houseRobber3(root->left) + houseRobber3(root->right);
		M[root] = max(rob, noRob);
		return max(rob, noRob);
	}
};
