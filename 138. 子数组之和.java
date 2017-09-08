import java.util.ArrayList;
public class Solution 
{
    public ArrayList<Integer> subarraySum(int[] nums) 
    {
        int[] sums = new int[nums.length+1];
        sums[0] = 0;
        for(int i=0;i<nums.length;++i)
        {
            sums[i+1]=sums[i]+nums[i];
        }
        ArrayList<Integer> result = new ArrayList<Integer>();
        for(int i=0;i<sums.length;++i)
        {
            boolean found = false;
            for(int j=0;j<sums.length;++j)
            {
                if(i!=j&&sums[j]-sums[i]==0)
                {
                    result.add(new Integer(i));
                    result.add(new Integer(j-1));
                    found = true;
                    break;
                }
            }
            if(found)
                break;
        }
        return result;
    }
}
