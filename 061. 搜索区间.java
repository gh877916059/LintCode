public class Solution 
{
    public int[] searchRange(int[] A, int target) 
    {
        int[] result = new int[2];
        boolean ok =true;
        if(A.length==0)
        {
            ok=false;
        }
        else
        {
            result[0]=lower_bound(A,target);
            if(result[0]==A.length||A[result[0]]!=target)
                ok=false;
        }
        if(ok)
        {
            result[1]=upper_bound(A,target)-1;
        }
        else
        {
            result[0]=-1;
            result[1]=-1;
        }
        return result;
    }
    private int lower_bound(int[] A,int target)
    {
        int x=0;
        int y=A.length;
        int m;
        while(x<y)
        {
            m=x+(y-x)/2;
            if(A[m]<target)
                x=m+1;
            else
                y=m;
        }
        return x;
    }
    private int upper_bound(int[] A,int target)
    {
        int x=0;
        int y=A.length;
        int m;
        while(x<y)
        {
            m=x+(y-x)/2;
            if(A[m]<=target)
                x=m+1;
            else
                y=m;
        }
        return x;
    }
}
