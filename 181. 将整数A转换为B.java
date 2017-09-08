class Solution 
{
    public static int bitSwapRequired(int a, int b) 
    {
    	int mask = 1;
        int result = 0;
        for(int i=0;i<32;++i)
        {
            if((a&mask)!=(b&mask))
                ++result;
            mask <<= 1;
        }
        return result;
    }
};
