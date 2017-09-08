class Solution
{
public:
	void sortColors2(vector<int> &colors, int k)
	{
		int n = colors.size();
		for (int i = 0; i<n;)
		{
			int temp = colors[i];
			if (temp<0)
				++i;
			else if (colors[temp - 1]>0)
			{
				colors[i] = colors[temp - 1];
				colors[temp - 1] = -1;
				if (temp - 1 < i)
					++i;
			}
			else
			{
				--colors[temp - 1];
				++i;
			}
		}
		int what_k = k;
		int index = n-1;
		int how_many_k = 0;
		while (index>=0)
		{
			how_many_k = -colors[what_k-1];
			for (int i = 0; i<how_many_k; ++i)
			{
				colors[index] = what_k;
				--index;
			}
			--what_k;
		}
		return;
	}
};
