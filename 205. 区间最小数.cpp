class SegmentTree
{
public:
	typedef struct SegmentTreeNode
	{
		int start, end, min;
		SegmentTreeNode *left, *right;
		SegmentTreeNode(int start, int end, int min)
		{
			this->start = start;
			this->end = end;
			this->min = min;
			this->left = this->right = NULL;
		}
	};
	SegmentTreeNode * root;
	SegmentTreeNode * build(vector<int>& A)
	{
		int start = 0;
		int end = A.size() - 1;
		return build(A, start, end);
	}
	SegmentTreeNode * build(vector<int>& A, int start, int end)
	{
		if (start>end)
			return NULL;
		if (start == end)
			return new SegmentTreeNode(start, end, A[start]);
		int mid = (start + end) / 2;
		SegmentTreeNode * left = build(A, start, mid);
		SegmentTreeNode * right = build(A, mid + 1, end);
		SegmentTreeNode * ret = new SegmentTreeNode(start, end, min(left->min, right->min));
		ret->left = left;
		ret->right = right;
	}
	int query(SegmentTreeNode *root, int start, int end)
	{
		if (!root)
			return INT_MAX;
		if (start <= root->start&&end >= root->end)
			return root->min;
		int mid = (root->start + root->end) / 2;
		if (mid<start)
			return query(root->right, start, end);
		else if (end<mid + 1)
			return query(root->left, start, end);
		else
			return min(query(root->left, start, mid), query(root->right, mid + 1, end));
	}
	SegmentTree(vector<int>& A)
	{
		root = build(A);
	}
	int query(int start, int end)
	{
		return query(root, start, end);
	}
};
class Solution {
public:
	vector<int> intervalMinNumber(vector<int> &A, vector<Interval> &queries)
	{
		SegmentTree tree(A);
		vector<int> result;
		for (auto i : queries)
		{
			result.push_back(tree.query(i.start, i.end));
		}
		return result;
	}
};
