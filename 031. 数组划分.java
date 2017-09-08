public class Solution 
{
    public int partitionArray(int[] nums, int k) 
    {
	    int[] temp = new int[nums.length];
	    int zuo = -1;
	    int you = nums.length;
	    for(int i=0;i<nums.length;++i)
	    {
	        if(nums[i]<k)
	        {
	            temp[++zuo]=nums[i];
	        }
	        else
	        {
	            temp[--you]=nums[i];
	        }
	    }
	    for(int i=0;i<nums.length;++i)
	    {
	        nums[i]=temp[i];
	    }
	    return you;
    }
}
