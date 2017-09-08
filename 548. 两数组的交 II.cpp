class Solution 
{
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) 
    {
        unordered_map<int, int> M;
		vector<int> result;
		for (auto i : nums1)
		{
			++M[i];
		}
		for (auto i : nums2)
		{
			if (M.find(i) != M.end())
			{
				result.push_back(i);
				--M[i];
				if(M[i]==0)
				    M.erase(i);
			}
		}
		return result;
    }
};
