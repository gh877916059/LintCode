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

class Solution {
public:
	void convert(TreeNode* root, int& sum)
	{
		if (root == NULL)
			return;
		convert(root->right, sum);
		root->val += sum;
		sum = root->val;
		convert(root->left, sum);
	}

	TreeNode* convertBST(TreeNode* root)
	{
		int sum = 0;
		convert(root, sum);
		return root;
	}
};
