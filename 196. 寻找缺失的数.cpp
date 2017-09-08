class Solution 
{  
public:  
    int findMissing(vector<int> &nums) 
    {  
        int n = nums.size();  
        if(n==0)  
            return 0;  
        else if(n==1)  
            return nums[0]==0?1:0;  
        int sum = 0;  
        for(auto x:nums)  
            sum+=x;  
        return (n)*(n+1)/2-sum;  
    }  
};  
