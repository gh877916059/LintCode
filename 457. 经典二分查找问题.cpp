class Solution 
{
public:
    int findPosition(vector<int>& A, int target) 
    {
        int x=0,y=A.size();
        if(y==0)
            return -1;
        while(x<y)
        {
            int mid=x+(y-x)/2;
            if(A[mid]<target)
                x=mid+1;
            else
                y=mid;
        }
        if(A[x]==target)
            return x;
        else
            return -1;
    }
};
