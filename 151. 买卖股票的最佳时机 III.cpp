class Solution 
{
public:
    int maxProfit(vector<int> &prices) 
    {
        int n = prices.size();
        if(n<=1)
            return 0;
        vector<int> left(n,0);
        vector<int> right(n,0);
        int min_price=prices[0];
        for(int i=1;i<n;++i)
        {
            min_price=min(prices[i],min_price);
            left[i]=max(left[i-1],prices[i]-min_price);
        }
        right[n-1]=0;
        int max_price=prices[n-1];
        for(int i=n-2;i>=0;--i)
        {
            max_price=max(prices[i],max_price);
            right[i]=max(right[i+1],max_price-prices[i]);
        }
        int profit=0;
        for(int i=0;i<n;++i)
        {
            profit=max(left[i]+right[i],profit);
        }
        return profit;
    }
};
