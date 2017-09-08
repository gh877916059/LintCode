class Solution 
{
public:
    int removeElement(vector<int> &A, int elem) 
    {
        int res = 0;
        for (int i = 0; i < A.size(); ++i) 
        {
            if (A[i] != elem) 
                A[res++] = A[i];
        }
        return res;
    }
};
