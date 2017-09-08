class Solution {
public:
    vector<vector<int> > result;
    bool ok(vector<int> &nums, int a, int b)
    {
	    if (b>a)
		    for (int i = a; i<b; i++)
			    if (nums[i] == nums[b])
				    return false;
	    return true;
    }
    vector<vector<int> > permuteUnique(vector<int> &nums) 
    {
        if(nums.size()==0)
        {
            result.push_back(nums);
            return result;
        }
        perm(nums,0,nums.size()-1);
        return result;
    }
    void perm(vector<int> &nums, int k, int m)
    {
	    int i;
	    if (k == m)
	    {
		    result.push_back(nums);
		    return;
	    }
	    else for (i = k; i <= m; i++)
		    if (ok(nums, k, i))
		    {
			    swap(nums[k], nums[i]);
			    perm(nums, k + 1, m);
			    swap(nums[k], nums[i]);
		    }
    }
};
