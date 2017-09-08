class Solution 
{
public:
    Solution(vector<int> A) 
    {
        root = build(A);
    }
    long long query(int start, int end) 
    {
        return query(root, start, end);
    }
    void modify(int index, int value) 
    {
        modify(root,index,value);
    }
private:
    typedef struct SegmentTreeNode
	{
		int start, end;
		long long sum;
		SegmentTreeNode *left, *right;
		SegmentTreeNode(int start, int end, long long sum)
		{
			this->start = start;
			this->end = end;
			this->sum = sum;
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
		SegmentTreeNode * ret = new SegmentTreeNode(start, end, left->sum + right->sum);
		ret->left = left;
		ret->right = right;
	}
	long long query(SegmentTreeNode *root, int start, int end)
	{
		if (!root)
			return INT_MAX;
		if (start <= root->start&&end >= root->end)
			return root->sum;
		int mid = (root->start + root->end) / 2;
		if (mid<start)
			return query(root->right, start, end);
		else if (end<mid + 1)
			return query(root->left, start, end);
		else
			return query(root->left, start, mid) + query(root->right, mid + 1, end);
	}
	void modify(SegmentTreeNode *root, int index, int value) 
    {  
        if(root==NULL||index<root->start||index>root->end)
            return;
        if(root->start==root->end)
        {  
            if(root->start==index)  
                root->sum=value;  
            return ;  
        }  
        modify(root->left,index,value);  
        modify(root->right,index,value);  
        root->sum=root->left->sum+root->right->sum;  
    }  
};
class SegmentTree
{
public:
	typedef struct SegmentTreeNode
	{
		int start, end;
		long long sum;
		SegmentTreeNode *left, *right;
		SegmentTreeNode(int start, int end, long long sum)
		{
			this->start = start;
			this->end = end;
			this->sum = sum;
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
		SegmentTreeNode * ret = new SegmentTreeNode(start, end, left->sum + right->sum);
		ret->left = left;
		ret->right = right;
	}
	long long query(SegmentTreeNode *root, int start, int end)
	{
		if (!root)
			return INT_MAX;
		if (start <= root->start&&end >= root->end)
			return root->sum;
		int mid = (root->start + root->end) / 2;
		if (mid<start)
			return query(root->right, start, end);
		else if (end<mid + 1)
			return query(root->left, start, end);
		else
			return query(root->left, start, mid) + query(root->right, mid + 1, end);
	}
	SegmentTree(vector<int>& A)
	{
		root = build(A);
	}
	long long query(int start, int end)
	{
		return query(root, start, end);
	}
};
