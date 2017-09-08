public class Solution 
{
    public String DeleteDigits(String A, int k) 
    {
        char[] A_s = A.toCharArray();
        int last_index = A_s.length-1;
        for(int i=0;i<k;++i)
        {
            last_index = A_s.length-i-1;
            int j=0;
            for(;j<=last_index;++j)
            {
                if((j+1)==A_s.length-i||A_s[j]>A_s[j+1])
                    break;
            }
            char temp=A_s[j];
            for(int ii=j+1;ii<=last_index;++ii)
            {
                A_s[ii-1]=A_s[ii];
            }
            A_s[last_index]=temp;
            --last_index;
        }
        int begin_index = 0;
        for(int i=0;i<=last_index;++i)
        {
            if(A_s[i]!='0')
            {
                begin_index=i;
                break;
            }
        }
        String result = "";
        for(int i=begin_index;i<=last_index;++i)
        {
            result+=A_s[i];
        }
        return result;
    }
}
