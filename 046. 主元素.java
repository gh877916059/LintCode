public class Solution 
{
    public int majorityNumber(ArrayList<Integer> nums) 
    {
        int result = nums.get(0);
        int counter = 1;
        for(int i=1;i<nums.size();++i)
        {
            if(result!=nums.get(i))
                counter--;
            else
                counter++;
            if(counter<=0)
            {
                result = nums.get(i);
                counter=1;
            }
        }
        return result;
    }
}
