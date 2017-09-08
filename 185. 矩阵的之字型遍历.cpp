class Solution
{
public:
	vector<int> printZMatrix(vector<vector<int> > &matrix)
	{
		vector<int> result;
		int n = matrix.size();
		if (n == 0)
			return result;
		int m = matrix[0].size();
		if (m == 0)
			return result;
		int count = n*m;
		vector<int> array(count, 0);
		int r = 0, c = 0;
		array[0] = matrix[0][0];
		for (int i = 1; i<count;)
		{
			while (i<count&&r - 1 >= 0 && c + 1<m)
			{
				array[i++] = matrix[--r][++c];
			}
			if (i<count&&c + 1<m)
				array[i++] = matrix[r][++c];
			else if (i<count&&r + 1<n)
				array[i++] = matrix[++r][c];
			while (i<count&&r + 1<n&&c - 1 >= 0)
			{
				array[i++] = matrix[++r][--c];
			}
			if (i<count&&r + 1<n)
				array[i++] = matrix[++r][c];
			else if (i<count&&c + 1<m)
				array[i++] = matrix[r][++c];
		}
		return array;
	}
};
