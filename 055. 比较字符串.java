public class Solution {
    public boolean compareStrings(String A, String B) 
    {
        int[] hasA = new int[26];
        int[] hasB = new int[26];
        char[] As = A.toCharArray();
        char[] Bs = B.toCharArray();
        for(int i=As.length-1;i>=0;--i)
        {
            ++hasA[hash(As[i])];
        }
        for(int i=Bs.length-1;i>=0;--i)
        {
            ++hasB[hash(Bs[i])];
        }
        for(int i=hasA.length-1;i>=0;--i)
        {
            if(hasA[i]<hasB[i])
                return false;
        }
        return true;
    }
    private int hash(char A)
    {
        return A-'A';
    }
}
