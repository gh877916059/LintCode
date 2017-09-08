class Solution 
{
    public int[] mergeSortedArray(int[] A, int[] B) 
    {
        int[] result = new int[A.length+B.length];
        int Ai=0;
        int Bi=0;
        int i=0;
        while(Ai<A.length&&Bi<B.length)
        {
            if(A[Ai]<=B[Bi])
                result[i++]=A[Ai++];
            else
                result[i++]=B[Bi++];
        }
        while(Ai<A.length)
            result[i++]=A[Ai++];
        while(Bi<B.length)
            result[i++]=B[Bi++];
        return result;
    }
}
