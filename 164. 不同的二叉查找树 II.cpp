class Solution
{
public:
	vector<TreeNode *> generateTrees(int n)
	{
		return generate(1, n);
	}
	vector<TreeNode *> generate(int start, int end)
	{
		vector<TreeNode *> rst;
		if (start>end)
		{
			rst.push_back(NULL);
			return rst;
		}
		for (int i = start; i<=end; ++i)
		{
			vector<TreeNode *> left = generate(start, i - 1);
			vector<TreeNode *> right = generate(i + 1, end);
			for (auto l : left)
			{
				for (auto r : right)
				{
					TreeNode* root = new TreeNode(i);
					root->left = l;
					root->right = r;
					rst.push_back(root);
				}
			}
		}
		return rst;
	}
};
