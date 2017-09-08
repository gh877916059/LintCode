class Solution 
{
public:
    int query(SegmentTreeNode *root, int start, int end) 
    {
		if (!root)
			return 0;
		if (start <= root->start&&end >= root->end)
			return root->count;
		int mid = (root->start + root->end) / 2;
		if (mid<start)
			return query(root->right, start, end);
		else if (end<mid + 1)
			return query(root->left, start, end);
		else
			return query(root->left, start, mid) + query(root->right, mid + 1, end);
    }
};
