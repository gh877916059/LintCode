class Solution 
{  
public:  
    int firstMissingPositive(vector<int> A) 
    {  
        int n = A.size();  
        for(int i=0;i<n;)  
        {  
            if(A[i]==i+1)  
                i++;  
            else  
            {  
                if(A[i]>=1&&A[i]<=n&& A[A[i]-1]!=A[i])  
                    swap(A[i],A[A[i]-1]);  
                else  
                    i++;  
            }  
        }  
        for(int i=0;i<n;i++)  
            if(A[i]!=i+1)  
                return i+1;  
        return n+1;  
    }  
};  
