class Solution 
{
public:
    SegmentTreeNode * build(vector<int>& A) 
    {
        int start=0;
        int end=A.size()-1;
        return build(A,start,end);
    }
    SegmentTreeNode * build(vector<int>& A,int start,int end)
    {
        if(start>end)
            return NULL;
        if(start==end)
            return new SegmentTreeNode(start,end,A[start]);
        int mid=(start+end)/2;
        SegmentTreeNode * left = build(A,start,mid);
        SegmentTreeNode * right = build(A,mid+1,end);
        SegmentTreeNode * ret = new SegmentTreeNode(start,end,max(left->max,right->max));
        ret->left=left;
        ret->right=right;
    }
};
