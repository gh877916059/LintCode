class Solution 
{
public:
    int nthSuperUglyNumber(int n, vector<int>& primes) 
    {
        vector<int> chou;
        chou.push_back(1);
        vector<int> indexs(primes.size(),0);
        for(int i=1;i<n;++i)
        {
            int next=INT_MAX;
            for(int j=0;j<primes.size();++j)
            {
                next=min(next,primes[j]*chou[indexs[j]]);
            }
            for(int j=0;j<primes.size();++j)
            {
                if(next==primes[j]*chou[indexs[j]])
                    ++indexs[j];
            }
            chou.push_back(next);
        }
        return chou[chou.size()-1];
    }
};
