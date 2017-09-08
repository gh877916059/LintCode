class Solution 
{  
public:  
    void rerange(vector<int> &A) 
    {  
        int n = A.size();
        if(n<=1)
            return;
        int zheng=0;
        int fu=0;
        for(auto i:A)
        {
            if(i>0)
                ++zheng;
            if(i<0)
                ++fu;
        }
        int zheng_index=0;
        int fu_index=1;
        if(fu>zheng)
        {
            fu_index=0;
            zheng_index=1;
        }
        while(fu_index<n&&zheng_index<n)
        {
            while(fu_index<n&&A[fu_index]<0)
                fu_index+=2;
            while(zheng_index<n&&A[zheng_index]>0)
                zheng_index+=2;
            if(fu_index<n&&zheng_index<n)
                swap(A[zheng_index],A[fu_index]);
        }
    }  
}; 
