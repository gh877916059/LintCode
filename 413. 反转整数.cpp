class Solution 
{
public:
    int reverseInteger(int n) 
    {
        bool is_fu =false;
        if(n<0)
        {
            is_fu=true;
            n=-n;
        }
        long long long_n;
        stringstream ss;
        ss<<n;
        string str = ss.str();
        string str1(str.rbegin(),str.rend());
        ss.str(str1);
        ss>>long_n;
        if(is_fu)
            long_n=-long_n;
        if(long_n<INT_MIN||long_n>INT_MAX)
            n=0;
        else
            n=(int)long_n;
        return n;
    }
};
