class Solution 
{
public:
    static Solution* getInstance() 
    {
        return instance;
    }
private:
    Solution()
    {
    }
    Solution(const Solution&)
    {
    }
    Solution& operator=(const Solution&)
    {
    }
    static Solution* instance = new Solution();
};
