class Solution 
{
    public boolean checkPowerOf2(int n) 
    {
        if(n<=0)
            return false;
        int count = 0;
        int mask = 1;
        for(int i=0;i<31;++i)
        {
            if((mask&n)==mask)
                ++count;
            mask<<=1;
        }
        if(count==1)
            return true;
        else
            return false;
    }
};
