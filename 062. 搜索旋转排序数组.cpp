public class Solution 
{
    public int search(int[] A, int target) 
    {
        if(A.length==0)
            return -1;
        int min_index=0;
        int x=0;
        int y=A.length;
        int m;
        if(A[0]>A[A.length-1])
        {
            while(x<y)
            {
                m=x+(y-x)/2;
                if(A[m]>A[x])
                {
                    x=m+1;
                    if(A[x]<A[y-1])
                        break;
                }
                else
                {
                    y=m;
                    if(A[x]<A[y-1])
                    {
                        x=y;
                        break;
                    }
                }
            }
            min_index=x;
        }
        if(target<=A[A.length-1])
        {
            x=min_index;
            y=A.length;
        }
        else
        {
            x=0;
            y=min_index;
        }
        while(x<y)
        {
            m=x+(y-x)/2;
            if(A[m]>=target)
                y=m;
            else
                x=m+1;
        }
        if(A[x]==target)
            return x;
        else
            return -1;
    }
}
