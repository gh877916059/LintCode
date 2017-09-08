class Solution 
{
    public void mergeSortedArray(int[] A, int m, int[] B, int n) 
    {
        int Ai=0;
        int Bi=0;
        int temp;
        int yi_dong_end = m-1;
        for(int i=0;i<m+n;++i)
        {
            if(Bi>=n||(Ai<=yi_dong_end&&A[Ai]<=B[Bi]))
            {
                temp=A[Ai];
                ++Ai;
            }
            else
            {
                temp=B[Bi];
                ++Bi;
            }
            if(temp==A[i])
                ;
            else
            {
                for(int j=yi_dong_end;j>=i;--j)
                {
                    A[j+1]=A[j];
                }
                A[i]=temp;
                ++yi_dong_end;
                ++Ai;
            }
        }
    }
}
