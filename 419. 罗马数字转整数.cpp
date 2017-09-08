class Solution 
{
public:
    int romanToInt(string& s) 
    {
        if(s.length()==0)
            return 0;
        map<char,int> m;
        m['I']=1;
        m['V']=5;
        m['X']=10;
        m['L']=50;
        m['C']=100;
        m['D']=500;
        m['M']=1000;
        int length=s.length();
        int result = m[s[length-1]];
        for(int i=length-2;i>=0;--i)
        {
            if(m[s[i+1]]<=m[s[i]])
                result+=m[s[i]];
            else
                result-=m[s[i]];
        }
        return result;
    }
};
