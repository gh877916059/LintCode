class Solution 
{
public:
    string IntToStr(int n)
    {
        stringstream ss;
        ss<<n;
        return ss.str();
    }
    string countAndSay(int n) 
    {
        if(n<=0)
            return "";
        string result="1";
        for(int i=2;i<=n;++i)
        {
            string sb="";
            int count=1;
            for(int j=1;j<result.length();++j)
            {
                if(result[j]==result[j-1])
                    ++count;
                else
                {
                    sb+=IntToStr(count);
                    sb+=result[j-1];
                    count=1;
                }
            }
            sb+=IntToStr(count);
            sb+=result[result.length()-1];
            result=sb;
        }
        return result;
    }
};
