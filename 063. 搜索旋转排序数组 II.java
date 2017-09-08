public class Solution {
    public boolean search(int[] A, int target) 
    {
        switch(A.length)
        {
            case 0:
                return false;
            case 1:
                return A[0]==target;
        }
        int x=0;
        int y=A.length;
        int m;
        if(A[x]>=A[y-1])
        {
            while((x+1)<A.length&&A[x]==A[x+1])
                ++x;
            while((y-2)>=0&&A[y-1]==A[y-2])
                --y;
            while(x<y)
            {
                m=x+(y-x)/2;
                if(A[m]>=A[x])
                {
                    x=m+1;
                    if(A[x]<A[y-1]||x==y-1)
                        break;
                }
                else
                {
                    y=m;
                    if(A[x]<A[y-1]||x==y-1)
                    {
                        x=y;
                        break;
                    }
                }
            }
        }
        int min_index=x;
        if(target>=A[0])
        {
            x=0;
            y=min_index;
        }
        else
        {
            x=min_index;
            y=A.length;
        }
        while(x<y)
        {
            m=x+(y-x)/2;
            if(A[m]<target)
                x=m+1;
            else
                y=m;
        }
        if(x==A.length||A[x]!=target)
        {
            return false;
        }
        else
            return true;
    }
}
