class Solution 
{
public:
    void moveZeroes(vector<int>& nums) 
    {
        vector<int> temp;
        vector<int> temp2;
        for(auto i:nums)
        {
            if(i==0)
                temp2.push_back(i);
            else
                temp.push_back(i);
        }
        int index=0;
        for(auto i:temp)
        {
            nums[index++]=i;
        }
        for(auto i:temp2)
        {
            nums[index++]=i;
        }
        return;
    }
};
