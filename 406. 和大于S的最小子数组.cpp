class Solution 
{  
public:  
    int minimumSize(vector<int> &nums, int s) 
    {  
        if(nums.empty())  
            return -1;  
        int result=INT_MAX,begin=0,end=0,size=nums.size(),sum=0;  
        while(end<size)
        {  
            sum+=nums[end];  
            while(sum>=s&&end>=begin)
            {  
                if(result>end-begin+1)  
                    result=end-begin+1;  
                sum-=nums[begin];   
                ++begin;  
            }  
            ++end;  
        }  
        return result==INT_MAX?-1:result;  
    }  
};  
