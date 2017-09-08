class Solution {
public:
    void wiggleSort(vector<int>& nums) 
    {
        vector<int> tmp = nums;
        int n = nums.size(), k = (n + 1) / 2, j = n; 
        sort(tmp.begin(), tmp.end());
        for (int i = 0; i < n; ++i) 
        {
            nums[i] = i & 1 ? tmp[--j] : tmp[--k];
        }
    }
};
