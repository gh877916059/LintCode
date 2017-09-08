class Solution 
{
public:
    TreeNode *sortedArrayToBST(vector<int> &A) 
    {
        return sortedArrayToBST(A,0,A.size()-1);
    }
    TreeNode *sortedArrayToBST(vector<int> &A,int start,int end)
    {
        if(start>end)
            return NULL;
        if(start==end)
            return new TreeNode(A[start]);
        int mid=(start+end)/2;
        TreeNode* left = sortedArrayToBST(A,start,mid-1);
        TreeNode* right = sortedArrayToBST(A,mid+1,end);
        TreeNode* result = new TreeNode(A[mid]);
        result->left=left;
        result->right=right;
        return result;
    }
};


