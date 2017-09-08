class Solution 
{  
public:  
    int maxDiffSubArrays(vector<int> nums) 
    {  
        int x1 = deal(nums);  
        reverse(nums.begin(),nums.end());  
        int x2 = deal(nums);  
        return max(x1,x2);  
    }  
    int deal(vector<int> nums)  
    {  
        int n = nums.size();  
        vector<int> leftMax(n,0);  
        vector<int> rightMin(n,0);  
        int sum = 0;  
        int mx = INT_MIN;  
        for(int i=0;i<n;i++)  
        {  
            sum+=nums[i];  
            mx = max(sum,mx);  
            if(sum<0)  
                sum = 0;  
            leftMax[i] = mx;  
        }  
        sum = 0;  
        mx = INT_MAX;  
        for(int i=n-1;i>=0;i--)  
        {  
            sum+=nums[i];  
            mx = min(sum,mx);  
            if(sum>0)  
                sum = 0;  
            rightMin[i]=mx;  
        }  
        int ret = 0;  
        for(int i=1;i<n;i++)  
        {  
            ret = max(ret,abs(leftMax[i-1]-rightMin[i]));  
        }  
        return ret;  
    }  
};  
