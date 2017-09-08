class Solution 
{  
public:  
    int maxArea(vector<int> &heights) 
    {  
        int ret = 0;  
        int r = heights.size()-1;  
        int l = 0;  
        while (l < r)  
        {  
            ret = max(ret,min(heights[l],heights[r])*(r-l));  
            if(heights[l]<heights[r])  
                l++;  
            else   
                r--;  
        }  
        return ret;  
    }  
};  
