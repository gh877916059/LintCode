class Solution 
{
public:
    char zhuanHuan(char a)
    {
        if(a>='a'&&a<='z')
            return a;
        if(a>='0'&&a<='9')
            return a;
        if(a>='A'&&a<='Z')
            return a+('a'-'A');
        else
            return -1;
    }
    bool isPalindrome(string& s) 
    {
        string str;
        for(auto i:s)
        {
            char temp=zhuanHuan(i);
            if(temp!=-1)
                str+=temp;
        }
        int len=str.length();
        int i=0;
        int j=len-1;
        while(i<j)
        {
            if(str[i]!=str[j])
                return false;
            ++i;
            --j;
        }
        return true;
    }
};
