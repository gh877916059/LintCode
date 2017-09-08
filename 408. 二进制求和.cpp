class Solution 
{
public:
    string addBinary(string& a, string& b) 
    {
        string result;
        string a_fan(a.rbegin(),a.rend());
        string b_fan(b.rbegin(),b.rend());
        int jin_wei=0;
        int i=0;
        for(;i<min(a_fan.length(),b_fan.length());++i)
        {
            int temp=a_fan[i]+b_fan[i]-'0'-'0'+jin_wei;
            if(temp%2==0)
                result="0"+result;
            else
                result="1"+result;
            jin_wei=temp/2;
        }
        for(;i<a_fan.length();++i)
        {
            int temp=a_fan[i]-'0'+jin_wei;
            if(temp%2==0)
                result="0"+result;
            else
                result="1"+result;
            jin_wei=temp/2;
        }
        for(;i<b_fan.length();++i)
        {
            int temp=b_fan[i]-'0'+jin_wei;
            if(temp%2==0)
                result="0"+result;
            else
                result="1"+result;
            jin_wei=temp/2;
        }
        if(jin_wei>0)
            result="1"+result;
        return result;
    }
};
