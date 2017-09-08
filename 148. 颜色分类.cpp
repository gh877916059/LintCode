class Solution
{  
public:  
    void sortColors(vector<int> &nums) 
    {  
        int l = 0;  
        int r = nums.size()-1;  
        for(int i=0;i<min((int)nums.size(),r+1);)  
        {  
            if(nums[i]==0)  
            {  
                if(i==l)  
                    i++;  
                else  
                    swap(nums[i],nums[l]);  
                l++;  
            }  
            else if(nums[i]==2)  
            {  
                swap(nums[i],nums[r]);  
                r--;  
            }  
            else  
                i++;  
        }  
    }  
};  
