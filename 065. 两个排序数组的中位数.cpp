class Solution
{
public:
	double findMedianSortedArrays(vector<int> A, vector<int> B)
	{
		int n_A = A.size();
		int n_B = B.size();
		if ((1 + n_A + n_B) % 2 == 0)
		{
			return (double)getMedian(A, B, 0, n_A - 1, 0, n_B - 1, (1 + n_A + n_B) / 2);
		}
		else
		{
			double wow = getMedian(A, B, 0, n_A - 1, 0, n_B - 1, (1 + n_A + n_B) / 2);
			wow += getMedian(A, B, 0, n_A - 1, 0, n_B - 1, (1 + n_A + n_B) / 2 + 1);
			wow /= 2;
			return wow;
		}
	}
	int getMedian(vector<int>& a, vector<int>& b, int s1, int n1, int s2, int n2, int k)
	{
		//x和y分别记录中间值的索引
		int x, y;
		x = (s1 + n1) / 2;        //记录a的中位数索引
		y = (s2 + n2) / 2;        //记录b的中位数索引
		if (s1 > n1)
			return b[s2 + k - 1];
		if (s2 > n2)
			return a[s1 + k - 1];
		if (a[x] <= b[y])
		{
			if (k <= (x - s1) + (y - s2) + 1)
				return getMedian(a,b,s1, n1, s2, y - 1, k);
			else
				return getMedian(a, b, x + 1, n1, s2, n2, k - (x - s1) - 1);
		}
		else
		{
			if (k <= (x - s1) + (y - s2) + 1)
				return getMedian(a, b, s1, x - 1, s2, n2, k);
			else
				return getMedian(a, b, s1, n1, y + 1, n2, k - (y - s2) - 1);
		}
		return 0;
	}
};
