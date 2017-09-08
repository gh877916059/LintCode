class Solution 
{
    public ArrayList<Interval> insert(ArrayList<Interval> intervals, Interval newInterval) 
    {
        if (intervals.size() == 0)
        {
            intervals.add(newInterval);
            return intervals;
        }
        for (int i=0;i<intervals.size();i++)
        {
            if (newInterval.end < intervals.get(i).start)
            {
                intervals.add(i,newInterval);
                break;
            }
            else if (newInterval.start > intervals.get(i).end)
            {
                if (i == intervals.size()-1)
                {
                    intervals.add(newInterval);
                }
                continue;
            }
            else
            {
                intervals.get(i).start = Math.min(intervals.get(i).start,newInterval.start);
                intervals.get(i).end = Math.max(intervals.get(i).end,newInterval.end);
                while (i<intervals.size()-1)
                {
                    if (intervals.get(i).end >= intervals.get(i+1).start)
                    {
                        intervals.get(i).end = Math.max(intervals.get(i).end,intervals.get(i+1).end);
                        intervals.remove(i+1);
                    }
                    i++;
                }
            }
        }

        return intervals;
    }
}
