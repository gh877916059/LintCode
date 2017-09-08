class Solution 
{  
public:  
    int maxProfit(vector<int> &prices) 
    {  
        /*
        int ret = 0;  
        if(prices.size()<2)  
            return ret;  
        int lowest = prices[0];  
        for(int i=1;i<prices.size();i++)  
        {  
            int cur = prices[i];  
            ret = max(ret,cur-lowest);  
            lowest  = min(lowest,cur);  
        }  
        return ret; 
        */
        return oneTime(prices,0,prices.size()-1);
    } 
        int oneTime(vector<int> &prices,int start,int end)
    {
        if(start>=end)
            return 0;
        int min_price=prices[start];
        int result=0;
        for(int i=start+1;i<=end;++i)
        {
            int temp=prices[i]-min_price;
            result=max(result,temp);
            min_price=min(min_price,prices[i]);
        }
        return result;
    }
};  
