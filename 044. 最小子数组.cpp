class Solution 
{
public:
    int minSubArray(vector<int> nums) 
    {
        int cur_min=nums[0];
        int min_min=nums[0];
        for(int i=1;i<nums.size();++i)
        {
            if(cur_min>=0)
                cur_min=nums[i];
            else
                cur_min+=nums[i];
            if(cur_min<min_min)
                min_min=cur_min;
        }
        return min_min;
    }
};
