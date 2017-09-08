import java.util.ArrayList;
import java.util.Collections;
public class Solution 
{
    public int[] subarraySumClosest(int[] nums) 
    {
        int[] sums = new int[nums.length+1];
        sums[0]=0;
        for(int i=0;i<nums.length;++i)
        {
            sums[i+1]=sums[i]+nums[i];
        }
        ArrayList<Pair> list = new ArrayList<Pair>();
        for(int i=0;i<sums.length;++i)
        {
            list.add(new Pair(i,sums[i]));
        }
        Collections.sort(list);
        int min_diff = Integer.MAX_VALUE;
        int[] result = new int[2];
        for(int i=0;i<list.size()-1;++i)
        {
            if(Math.abs(list.get(i+1).value-list.get(i).value)<min_diff)
            {
                min_diff=Math.abs(list.get(i+1).value-list.get(i).value);
                if(list.get(i).yuan_lai<list.get(i+1).yuan_lai)
                {
                    result[0]=list.get(i).yuan_lai;
                    result[1]=list.get(i+1).yuan_lai-1;
                }
                else
                {
                    result[0]=list.get(i+1).yuan_lai;
                    result[1]=list.get(i).yuan_lai-1;
                }
            }
        }
        return result;
    }
    class Pair implements Comparable
    {
        int yuan_lai;
        int value;
        public Pair(int a,int b)
        {
            yuan_lai = a;
            value = b;
        }
        @Override
        public int compareTo(Object other)
        {
            return Integer.valueOf(value).compareTo(Integer.valueOf(((Pair)other).value));
        }
    }
}
