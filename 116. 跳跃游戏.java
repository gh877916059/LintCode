public class Solution 
{
    public boolean canJump(int[] A) 
    {
        int zui_yuan=0;
        int i=0;
        while(i<=zui_yuan)
        {
            if(i+A[i]>zui_yuan)
                zui_yuan=i+A[i];
            ++i;
            if(zui_yuan>=A.length-1)
                return true;
        }
        return false;
    }
}
