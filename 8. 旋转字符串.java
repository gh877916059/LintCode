public class Solution 
{
    public void rotateString(char[] str, int offset) 
    {
        if (str == null || str.length <=1)
        {
            return;
        }
        int n = str.length;
        offset %= n;
        reverse(str,0,n-offset-1);
        reverse(str,n-offset,n-1);
        reverse(str,0,n-1);
    }
    public void reverse(char[] str,int start,int end)
    {
        for (int i=start,j=end;i<j;i++,j--)
        {
            char temp = str[i];
            str[i] = str[j];
            str[j] = temp;
        }
    }
}
