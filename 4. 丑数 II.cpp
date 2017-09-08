#include <list>
class Solution 
{
public:
    int nthUglyNumber(int n) 
    {
        vector<int> uglyNumSeq(1, 1);
        int i2 = 0, i3 = 0, i5 = 0;
        while (uglyNumSeq.size() < n) 
        {
            int n2 = uglyNumSeq[i2] * 2;
            int n3 = uglyNumSeq[i3] * 3;
            int n5 = uglyNumSeq[i5] * 5;
            int next = min(n2, min(n3, n5));
            if (next == n2) ++i2;
            if (next == n3) ++i3;
            if (next == n5) ++i5;
            uglyNumSeq.push_back(next);
        }
        return uglyNumSeq.back();
    }
};
