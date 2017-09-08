import java.util.Collections;
import java.util.ArrayList;
public class Solution 
{
   public static int[] nextPermutation(int[] nums) 
   {
        ArrayList<Integer> list = new ArrayList<Integer>();
        for(int i=nums.length-1;i>=0;--i)
        {
            for(int j=nums.length-1;j>i;--j)
            {
                if(nums[i]<nums[j])
                {
                    int temp=nums[i];
                    nums[i]=nums[j];
                    nums[j]=temp;
                    for(int k=i+1;k<nums.length;++k)
                    {
                        list.add(nums[k]);
                    }
                    Collections.sort(list);
                    for(int k=i+1;k<nums.length;++k)
                    {
                        nums[k]=list.get(k-i-1);
                    }
                    return nums;
                }
            }
        }
        for(int i=0;i<nums.length;++i)
        {
            list.add(nums[i]);
        }
        Collections.sort(list);
        for(int i=0;i<nums.length;++i)
        {
            nums[i]=list.get(i);
        }
        return nums;
   }
}
