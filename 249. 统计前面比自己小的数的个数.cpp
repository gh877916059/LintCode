class Node 
{
    public:
        int start, end, count;
        Node * left, * right;
        Node(int start, int end)
        {
            this->start = start;
            this->end = end;
            this->left = this->right = NULL;
            this->count = 0;
        }
};
class Solution 
{
public:
    Node * build(int start, int end) 
    {
        if(start > end) 
            return NULL;
        Node * root  = new Node(start, end);
        if(start < end) 
        {
            int mid = (start+end)>>1;
            root->left = build(start, mid);
            root->right = build(mid+1, end);
        }
        return root;
    } 
    int query(Node * root, int start, int end) 
    {
        if(root == NULL)
            return 0;
        if(start > end || root->start > end || root->end < start) 
            return 0;
        if(start <= root->start && end >= root->end) 
            return root->count;
        int mid = (root->start + root->end) >> 1;
        int leftCount = query(root->left, start, min(mid, end));
        int rightCount = query(root->right, max(mid, start), end);
        return leftCount + rightCount;
    }
    void insert(Node * root, int value) 
    {
        if(root == NULL) 
            return;
        if(root->start == root->end && root->start == value) 
        {
            root->count += 1; 
            return;
        }
        int mid = (root->start + root->end) >> 1;
        if(value <= mid) 
            insert(root->left, value);
        else 
            insert(root->right, value);
        root->count = root->left->count + (root->right ? root->right->count : 0);
    }
    vector<int> countOfSmallerNumberII(vector<int> &A) 
    {
        Node * root = build(0, 10005);
        vector<int> ret;
        for(int i = 0;i < A.size(); ++i) 
        {
            int cnt = query(root, 0, A[i]-1);
            ret.push_back(cnt);
            insert(root, A[i]);
        }
        return ret;
    }
};
