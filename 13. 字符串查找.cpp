class Solution 
{
public:
    int strStr(const char *source, const char *target) 
    {
        if(source==NULL||target==NULL)
            return -1;
        if(strlen(target)==0)
            return 0;
        if(strlen(source)==0)
            return -1;
        int s_i=0,t_i=0;
        vector<int> next = getNext(target);
        while(s_i<strlen(source)&&t_i<strlen(target))
        {
            if(source[s_i]==target[t_i])
            {
                ++s_i;
                ++t_i;
            }
            else
            {
                if(t_i==0)
                    ++s_i;
                else
                    t_i=next[t_i-1]+1;
            }
        }
        return (t_i==strlen(target))?(s_i-strlen(target)):-1;
    }
    vector<int> getNext(string target)
    {
        vector<int> next(target.length(),-1);
        int i,j;
        for(i=1;i<target.length();++i)
        {
            j=next[i-1];
            while(target[j+1]!=target[i]&&(j>=0))
                j=next[j];
            if(target[i]==target[j+1])
                next[i]=j+1;
            else
                next[i]=-1;
        }
        return next;
    }
};
