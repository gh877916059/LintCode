public class Solution 
{
    public int findMin(int[] nums) 
    {
        int x=0;
        int y=nums.length;
        int m;
        while(x<y&&nums[x]>nums[y-1])
        {
            m=x+(y-x)/2;
            if(nums[m]>nums[x])
            {
                x=m+1;
                if(nums[x]<=nums[y-1])
                    break;
            }
            else
            {
                y=m;
                if(nums[x]<=nums[y-1])
                {
                    x=y;
                    break;
                }
            }
        }
        return nums[x];
    }
}
