#include <iostream>
#include <vector>
#include <queue>
using namespace std;

/*
class TreeNode
{
public:
	int val;
	TreeNode *left, *right;
	TreeNode(int val) 
	{
		this->val = val;
		this->left = this->right = NULL;
    }
};
*/

class Solution 
{
public:
	vector<vector<int>> binaryTreePathSum(TreeNode *root, int target)
	{
		recursion(root, target);
		return result_vector;
	}
private:
	vector<int> curr_path;
	vector<vector<int>> result_vector;
	void recursion(TreeNode *root, int target)
	{
		if (root == NULL)
			return;
		int remaining = target - root->val;
		curr_path.push_back(root->val);
		if (remaining == 0 && root->left == NULL && root->right == NULL)
		{
			result_vector.push_back(curr_path);
		}
		recursion(root->left, remaining);
		recursion(root->right, remaining);
		curr_path.pop_back();
	}
};
