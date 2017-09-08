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

/*
class DoublyListNode 
{
public:
	int val;
	DoublyListNode *next, *prev;
	DoublyListNode(int val) 
	{
		this->val = val;
		this->prev = this->next = NULL;
	}
};
*/

class Solution {
public:
	DoublyListNode* bstToDoublyList(TreeNode* root) 
	{
		recursion(root);
		return head;
	}
	void recursion(TreeNode* root)
	{
		if (root == NULL)
			return;
		recursion(root->left);
		if (head == NULL)
		{
			head = new DoublyListNode(root->val);
			tail = head;
		}
		else
		{
			tail->next = new DoublyListNode(root->val);
			tail->next->prev = tail;
			tail = tail->next;
		}
		recursion(root->right);
	}
private:
	DoublyListNode* head = NULL;
	DoublyListNode* tail = NULL;
};
