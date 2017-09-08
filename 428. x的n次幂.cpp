class Solution
{
public:
	double myPow(double x, int n)
	{
		bool is_zheng = true;
		if (n<0)
		{
			n = -n;
			is_zheng = false;
		}
		if (n == 0)
			return 1;
		if (n == 1&&is_zheng)
			return x;
		if (n % 2 == 1)
		{
			if (is_zheng)
				return x*myPow(x, n / 2)*myPow(x, n / 2);
			else
				return 1 / (x*myPow(x, n / 2)*myPow(x, n / 2));
		}
		else
		{
			if (is_zheng)
				return myPow(x, n / 2)*myPow(x, n / 2);
			else
				return 1 / (myPow(x, n / 2)*myPow(x, n / 2));
		}
	}
};
