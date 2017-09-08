public class Solution 
{
    public int woodCut(int[] L, int k) 
    {
        if(L.length==0)
            return 0;
        int Len = 0;
        for(int i=0;i<L.length;++i)
        {
            if(L[i]>Len)
                Len=L[i];
        }
        int x=1;
        int y=Len;
        int m;
        while(x<y)
        {
            m=x+(y-x)/2;
            int sum=0;
            for(int i=0;i<L.length;++i)
            {
                sum+=L[i]/m;
            }
            if(sum<k)
                y=m;
            else
                x=m+1;
        }
        return x-1;
    }
}
