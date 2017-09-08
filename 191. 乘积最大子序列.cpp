class Solution 
{  
public:  
    int maxProduct(vector<int>& nums) 
    {  
        int posMax = nums[0];  
        int negMax = nums[0];  
        int ret = nums[0];  
        for(int i=1;i<nums.size();i++)  
        {  
            int tempPosMax = posMax;  
            int tempNegMax = negMax;  
            posMax = max(nums[i],max(nums[i]*tempPosMax,nums[i]*tempNegMax));  
            negMax = min(nums[i],min(nums[i]*tempPosMax,nums[i]*tempNegMax));  
            ret = max(ret,posMax);  
        }  
        return ret;  
    }  
};  
