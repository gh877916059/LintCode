class Solution 
{
public:
    long long permutationIndex(vector<int>& A) 
    {
        int n = A.size();
        if(n<=1)
            return (long long)(1);
        vector<long long> pai_lie(n+1,1);
        for(int i=2;i<=n;++i)
        {
            pai_lie[i]=i*pai_lie[i-1];
        }
        long long result=1;
        long long counter=0;
        for(int i=0;i<n;++i)
        {
            for(int j=i+1;j<n;++j)
            {
                if(A[i]>A[j])
                    ++counter;
            }
            result+=pai_lie[n-i-1]*counter;
            counter=0;
        }
        return result;
    }
};
