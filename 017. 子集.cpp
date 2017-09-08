class Solution 
{
public:
    vector<vector<int> > subsets(vector<int> &nums) 
    {
        size=nums.size();
        sort(nums.begin(),nums.end());
        subsets(nums,0);
    	return result;
    }
    void subsets(vector<int> &nums,int pos)
    {
        result.push_back(base);
        for(int i=pos;i<size;++i)
        {
            base.push_back(nums[i]);
            subsets(nums,i+1);
            base.pop_back();
        }
    }
private:
    vector<vector<int> > result;
    vector<int> base;
    int size;
};
