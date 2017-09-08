class Solution 
{
public:
    int hashCode(string key,int HASH_SIZE) 
    {
        int n=key.length();
        if(n==0)
            return 0;
        long ji_shu=1;
        long result=0;
        for(int i=n-1;i>=0;--i)
        {
            result=(result+(ji_shu*key[i])%HASH_SIZE)%HASH_SIZE;
            ji_shu=(ji_shu*33)%HASH_SIZE;
        }
        return result%HASH_SIZE;
    }
};
