class Solution 
{
public:
    int removeDuplicates(vector<int>& nums) 
    {
        int n=nums.size();
        if (n <= 1) 
            return n;
        int pre = 0, cur = 0;
        while (cur < n) 
        {
            if (nums[cur] == nums[pre]) 
                ++cur;
            else 
                nums[++pre] = nums[cur++];
        }
        return pre + 1;
    }
};
