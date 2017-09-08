class Solution
{
public:
	vector<int> intersection(vector<int>& nums1, vector<int>& nums2)
	{
		unordered_map<int, int> M;
		vector<int> result;
		for (auto i : nums1)
		{
			if (M.find(i) == M.end())
				M[i] = 1;
		}
		for (auto i : nums2)
		{
			if (M.find(i) != M.end())
			{
				result.push_back(i);
				M.erase(i);
			}
		}
		return result;
	}
};
