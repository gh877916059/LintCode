class Solution 
{
    public int findPeak(int[] A) 
    {
        int x=0;
        int y=A.length;
        int m=0;
        while(x<y)
        {
            m=x+(y-x)/2;
            if(m==A.length-1)
            {
                --m;
                break;
            }
            if(A[m-1]<A[m]&&A[m]>A[m+1])
                break;
            if(A[m-1]<A[m]&&A[m]<A[m+1])
                x=m+1;
            else if(A[m-1]>A[m]&&A[m]>A[m+1])
                y=m;
            else
                y=m;
        }
        return m;
    }
}
