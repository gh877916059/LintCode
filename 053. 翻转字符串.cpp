class Solution 
{
public:
    string reverseWords(string s) 
    {
        string cur="";
        stack<string> sta;
        int len = s.length();
        for(int i=0;i<len;++i)
        {
            if(s[i]==' '&&cur=="")
                ;
            else if(s[i]==' '&&cur!="")
            {
                sta.push(cur);
                cur="";
            }
            else
            {
                cur+=s[i];
            }
        }
        if(cur!="")
            sta.push(cur);
        cur="";
        while(!sta.empty())
        {
            string temp=sta.top();
            sta.pop();
            cur+=temp;
            if(!sta.empty())
                cur+=" ";
        }
        return cur;
    }
};
