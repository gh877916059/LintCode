public class Solution 
{
    public int searchInsert(int[] A, int target) 
    {
        return lower_bound(A,0,A.length,target);
    }
    private int lower_bound(int[] A,int x,int y,int v)
    {
        int m;
        while(x<y)
        {
            m = x+(y-x)/2;
            if(A[m]<v)
                x=m+1;
            else
                y=m;
        }
        return x;
    }
}
