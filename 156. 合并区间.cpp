#include <algorithm>
bool cmp(Interval a, Interval b)
{
	return a.start<b.start;
}
class Solution
{
public:
	vector<Interval> merge(vector<Interval> &intervals)
	{
		if (intervals.size() <= 1)
			return intervals;
		sort(intervals.begin(), intervals.end(), cmp);
		vector<Interval> result;
		int last = 0;
		for (int i = 1; i<intervals.size(); ++i)
		{
			Interval curt = intervals[i];
			if (curt.start <= intervals[last].end)
				intervals[last].end = max(intervals[last].end, curt.end);
			else
			{
				result.push_back(intervals[last]);
				last = i;
			}
		}
		result.push_back(intervals[last]);
		return result;
	}
};
