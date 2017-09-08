class Solution 
{
    public int sqrt(int x) 
    {
        int result = lower_bound(0,x,x);
        if(result*result==x)
            return result;
        else
            return result-1;
    }
    private int lower_bound(long x,long y,long v)
    {
        long m;
        while(x<y)
        {
            m = x+(y-x)/2;
            if(m*m<v)
                x=m+1;
            else
                y=m;
        }
        return (int)x;
    }
}
