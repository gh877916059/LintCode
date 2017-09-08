class Solution 
{
public:
    vector<int> singleNumberIII(vector<int> &A) 
    {
        int Xor = 0, n = A.size();  
        for ( int i = 0; i < n; ++i ) Xor ^= A[i];  
        int k = 0;  
        while ( Xor % 2 == 0 )  
        {  
            ++k;  
            Xor >>= 1;  
        }  
        int r1 = 0, r2 = 0;  
        for ( int i = 0; i < n; ++i )  
        {  
            int kb = (A[i]>>k) % 2;  
            if ( kb == 0 ) r1 ^= A[i];  
            else r2 ^= A[i];  
        }  
        vector<int> res;  
        res.push_back(r1);  
        res.push_back(r2);  
        return res;  
    }
};
