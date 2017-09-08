class Solution 
{  
public:  
    int divide(int dividend, int divisor) 
    {  
        bool resultGreatThanZero = true;  
        if(dividend>0&&divisor<0||dividend<0&&divisor>0)  
            resultGreatThanZero = false;  
        long long ret = 0;  
        long long d1 = abs((long long)dividend);  
        long long d2 = abs((long long)divisor);  
        while(d1>=d2)  
        {  
            long long temp = d2;  
            long long cnt = 1;  
            while(d1>=temp)  
            {  
                d1-=temp;  
                ret+=cnt;  
                cnt = cnt<<1;  
                temp = temp<<1;  
            }  
        }  
        if(!resultGreatThanZero)  
            ret*=-1;  
        if(ret<(long long)INT_MIN||ret>(long long)INT_MAX)  
            return INT_MAX;  
        return ret;  
    }  
};  
