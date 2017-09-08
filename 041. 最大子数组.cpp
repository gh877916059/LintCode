class Solution 
{
public:    
    int maxSubArray(vector<int> nums) 
    {
        int size=nums.size();
        int cur_sum=nums[0];
        int max_sum=nums[0];
        for(int i=1;i<nums.size();++i)
        {
            if(cur_sum<=0)
                cur_sum=0;
            cur_sum+=nums[i];
            if(cur_sum>max_sum)
                max_sum=cur_sum;
        }
        return max_sum;
    }
};
