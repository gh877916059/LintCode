class Solution
{
public:
	void sortNutsAndBolts(vector<string> &nuts, vector<string> &bolts, Comparator compare)
	{
		if (nuts.size() != bolts.size())
			return;
		qsort(nuts, bolts, compare, 0, nuts.size() - 1);
	}
	void qsort(vector<string> &nuts, vector<string> &bolts, Comparator compare, int l, int u)
	{
		if (l >= u)
			return;
		int part_inx = partition(nuts, bolts[l], compare, l, u);
		partition(bolts, nuts[part_inx], compare, l, u);
		qsort(nuts, bolts, compare, l, part_inx - 1);
		qsort(nuts, bolts, compare, part_inx + 1, u);
	}
	int partition(vector<string> &str, string pivot, Comparator compare, int l, int u)
	{
		int m = l;
		for (int i = l + 1; i <= u; ++i)
		{
			if (compare.cmp(str[i], pivot) == -1 || compare.cmp(pivot, str[i]) == 1)
			{
			    ++m;
				swap(str[i], str[m]);
			}
			else if (compare.cmp(str[i], pivot) == 0 || compare.cmp(pivot, str[i]) == 0)
			{
				swap(str[i], str[l]);
				--i;
			}
		}
		swap(str[m], str[l]);
		return m;
	}
};
