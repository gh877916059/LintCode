class Solution 
{
public:
    vector<int> medianII(vector<int>& nums)
    {
        vector<int> result;
        if (nums.size() == 0)
            return result;
        int median = nums[0];
        priority_queue<int> max_heap, min_heap;
        result.push_back(median);
        for (int i = 1; i < nums.size(); ++i)
        {
            if (nums[i] < median)
                max_heap.push(nums[i]);
            else
                min_heap.push(-nums[i]);
            if (max_heap.size()>min_heap.size()+ 1)
            {
                min_heap.push(-median);
                median = max_heap.top();
                max_heap.pop();
            }
            else if (max_heap.size() < min_heap.size())
            {
                max_heap.push(median);
                median = -min_heap.top();
                min_heap.pop();
            }
            result.push_back(median);
        }
        return result;
    }
};
