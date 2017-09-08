class Solution 
{
public:
    vector<vector<int> > vv;
    int nn;
    map<int, int> mp;
    void dfs_2(int ld, int rd, vector<int> nums)
    {
        if(ld == rd)
        {
            vv.push_back(nums);
            return ;
        }
        for(int i=ld; i<=rd; ++i)
        {
            swap(nums[ld], nums[i]);
            dfs_2(ld+1, rd, nums);
            swap(nums[ld], nums[i]);
        }
    }
    vector<vector<int> > permute(vector<int> nums) {
        sort(nums.begin(), nums.end());
        if(nums.size()==0)
        {
            vector<int> temp;
            vv.push_back(temp);
        }
        dfs_2(0, nums.size()-1, nums);
        return vv;
    }
};
