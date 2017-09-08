class Solution 
{
public:
    bool checkEmpty(const char *p)
    {
        int p_l=strlen(p);
        if(p_l%2!=0)
            return false;
        for(int i=1;i<p_l;i+=2)
        {
            if(p[i]!='*')
                return false;
        }
        return true;
    }
    bool isMatch(const char *s, const char *p) 
    {
        int i=0,j=0;
        int s_l=strlen(s),p_l=strlen(p);
        if(s_l==0)
        {
            return checkEmpty(p);
        }
        if(p_l==0)
            return false;
        char c1 = s[0];
        char d1 = p[0],d2='0';
        if(p_l>1)
            d2=p[1];
        if(d2=='*')
        {
            if(d1 == '.' || c1 == d1)
                return isMatch(s+1,p)||isMatch(s,p+2);
            else
                return isMatch(s,p+2);
        }
        else
        {
            if(d1 == '.' || c1 == d1)
                return isMatch(s+1,p+1);
            else
                return false;
        }
    }
};
 
