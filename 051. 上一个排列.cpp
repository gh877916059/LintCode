class Solution 
{
public:
    vector<int> previousPermuation(vector<int> &nums) 
    {
        int n = nums.size();
        vector<int> temp;
        for(int i=n-1;i>=0;--i)
        {
            for(int j=n-1;j>i;--j)
            {
                if(nums[i]>nums[j])
                {
                    swap(nums[i],nums[j]);
                    for(int k=i+1;k<n;++k)
                        temp.push_back(nums[k]);
                    sort(temp.begin(),temp.end());
                    reverse(temp.begin(),temp.end());
                    for(int k=i+1;k<n;++k)
                        nums[k]=temp[k-i-1];
                    return nums;
                }
            }
        }
        sort(nums.begin(),nums.end());
        reverse(nums.begin(),nums.end());
        return nums;
    }
};
