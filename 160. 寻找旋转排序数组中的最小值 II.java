public class Solution 
{
    public int findMin(int[] num) 
    {
        switch(num.length)
        {
            case 1:
                return num[0];
        }
        int x=0;
        int y=num.length;
        int m;
        if(num[x]<num[y-1])
            return num[x];
        while((x+1)<num.length&&num[x]==num[x+1])
            ++x;
        while((y-2)>=0&&num[y-1]==num[y-2])
            --y;
        while(x<y)
        {
            m=x+(y-x)/2;
            if(num[m]>=num[x])
            {
                x=m+1;
                if(num[x]<num[y-1]||x==y-1)
                    break;
            }
            else
            {
                y=m;
                if(num[x]<num[y-1]||x==y-1)
                {
                    x=y;
                    break;
                }
            }
        }
        return num[x];
    }
}
