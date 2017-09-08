class Solution 
{
public:
vector<vector<int>> levelOrder(TreeNode *root)
{
	int counter1 = 0;
	int counter2 = 0;
	queue<TreeNode*> dui_lie;
	vector<vector<int>> result;
	if (root == NULL)
		return result;
	dui_lie.push(root);
	++counter1;
	vector<int> ke_yi;
	while (!dui_lie.empty())
	{
		TreeNode* temp = dui_lie.front();
		ke_yi.push_back(temp->val);
		dui_lie.pop();
		if (temp->left != NULL)
		{
			dui_lie.push(temp->left);
			++counter2;
		}
		if (temp->right != NULL)
		{
			dui_lie.push(temp->right);
			++counter2;
		}
		--counter1;
		if (counter1 == 0)
		{
			result.push_back(ke_yi);
			counter1 = counter2;
			counter2 = 0;
			ke_yi.clear();
		}
	}
	return result;
}
};
