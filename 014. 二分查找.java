class Solution 
{
    public int binarySearch(int[] nums, int target) 
    {
        int x=0;
        int y=nums.length;
        int m;
        while(x<y)
        {
            m=x+(y-x)/2;
            if(nums[m]<target)
                x=m+1;
            else
                y=m;
        }
        if(x>=nums.length||nums[x]!=target)
            return -1;
        else
            return x;
    }
}
