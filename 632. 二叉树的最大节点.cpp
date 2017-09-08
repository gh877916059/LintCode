#include <iostream>
#include <vector>
#include <stack>
#include <string>
#include <algorithm>
#include <functional>
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
	TreeNode* maxNode(TreeNode* root)
	{
		if (root == NULL)
			return root;
		auto ret = root;
		auto left_max_node = maxNode(root->left);
		if (left_max_node != NULL)
		{
			if (left_max_node->val > ret->val)
			{
				ret = left_max_node;
			}
		}
		auto right_max_node = maxNode(root->right);
		if (right_max_node != NULL)
		{
			if (right_max_node->val > ret->val)
			{
				ret = right_max_node;
			}
		}
		return ret;
	}
};
