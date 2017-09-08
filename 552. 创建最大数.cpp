class Solution {
public:
    vector<int> maxNumber(vector<int>& nums1, vector<int>& nums2, int k) 
    {
        int m = nums1.size(), n = nums2.size();
        vector<int> res;
        for (int i = max(0, k - n); i <= min(k, m); ++i) 
        {
            res = max(res, mergeVector(maxVector(nums1, i), maxVector(nums2, k - i)));
        }
        return res;
    }
    vector<int> maxVector(vector<int> nums, int k) 
    {
        int drop = nums.size() - k;
        vector<int> res;
        for (int num : nums) 
        {
            while (drop && res.size() && res.back() < num) 
            {
                res.pop_back();
                --drop;
            }
            res.push_back(num);
        }
        res.resize(k);
        return res;
    }
    vector<int> mergeVector(vector<int> nums1, vector<int> nums2) 
    {
        vector<int> res;
        while (nums1.size() + nums2.size()) 
        {
            vector<int> &tmp = nums1 > nums2 ? nums1 : nums2;
            res.push_back(tmp[0]);
            tmp.erase(tmp.begin());
        }
        return res;
    }
};
