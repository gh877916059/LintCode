class Solution 
{
    public int updateBits(int n, int m, int i, int j) 
    {
        int mask=1;
        int temp=0;
        int max_int =-1;
        for(int ii=0;ii<=31;++ii)
        {
            if(ii>=i&&ii<=j)
            {
                temp=~mask;
                max_int&=temp;
            }
            mask<<=1;
        }
        m<<=i;
        n&=max_int;
        n|=m;
        return n;
    }
}
