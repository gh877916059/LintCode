class Solution 
{
public:
    SegmentTreeNode * build(int start, int end) 
    {
        if(start>end)
            return NULL;
        SegmentTreeNode* ret = new SegmentTreeNode(start,end);
        if(start<end)
        {
            int mid=(start+end)/2;
            ret->left=build(start,mid);
            ret->right=build(mid+1,end);
        }
        return ret;
    }
};
