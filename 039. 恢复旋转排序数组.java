public class Solution 
{
    public void recoverRotatedSortedArray(ArrayList<Integer> nums) 
    {
        for (int i=0;i<nums.size()-1;i++)
        {
            if (nums.get(i) > nums.get(i+1))
            {
                reverse(nums,0,i);
                reverse(nums,i+1,nums.size()-1);
                reverse(nums,0,nums.size()-1);
                return;
            }
        }
    }
    private void reverse(ArrayList<Integer> nums,int start,int end)
    {
        for (int i=start,j=end;i<j;i++,j--)
        {
            int temp = nums.get(i);
            nums.set(i, nums.get(j));
            nums.set(j, temp);
        }
    }
}
