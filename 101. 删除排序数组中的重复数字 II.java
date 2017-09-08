public class Solution 
{
    public int removeDuplicates(int[] nums) 
    {
        int real_length = nums.length;
        for(int i=0;i<real_length;++i)
        {
            int ci_shu=1;
            for(int j=i+1;j<real_length;++j)
            {
                if(nums[i]==nums[j])
                {
                    ++ci_shu;
                }
                if(nums[i]!=nums[j]||j==real_length-1)
                {
                    if(ci_shu>2)
                    {
                        for(int k=j-1;k<real_length;++k)
                        {
                            nums[k-ci_shu+2]=nums[k];
                        }
                        real_length-=ci_shu-2;
                    }
                    if(ci_shu>=2)
                        ++i;
                    break;
                }
            }
        }
        return real_length;
    }
}
