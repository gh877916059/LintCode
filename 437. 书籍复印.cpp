class Solution 
{  
public:  
    int copyBooks(vector<int> &pages, int k) 
    {  
        int l = 0;  
        int r = 99999999;  
        while(l<r)  
        {  
            int mid = l+(r-l)/2;  
            if(check(mid,pages,k))  
            {  
                r = mid;  
            }  
            else  
                l = mid+1;  
        }  
        return l;  
          
    }  
    bool check(int index,vector<int>& pages,int k)  
    {  
        int cnt = 0;  
        int sum = 0;  
        int i = 0;  
        while(i<pages.size())  
        {  
            if(sum+pages[i]<=index)  
            {  
                sum+=pages[i++];  
            }  
            else if(pages[i]<=index)  
            {  
                cnt++;  
                sum = 0;  
            }  
            else  
                return false;  
        }  
        if(sum!=0)  
            cnt++;  
        return cnt<=k;  
    }  
};  
