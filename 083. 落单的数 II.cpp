class Solution 
{
public:
    int singleNumberII(vector<int> &A) 
    {
        vector<int> bit(32);  
        for(auto x:A)  
        {  
            for(int i=0;i<32;i++)  
            {  
                if((1<<i)&x)  
                    bit[31-i] = (bit[31-i]+1)%3;  
            }  
        }  
        int ret = 0;  
        for(int i=0;i<32;i++)  
        {  
            ret = ret*2+bit[i];  
        }  
        return ret;  
    }
};
