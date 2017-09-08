class Solution 
{
public:
    int replaceBlank(char string[], int length) 
    {
        if(length==0)
            return 0;
        int num=0;
        for(int i=0;i<length;++i)
            if(string[i]==' ')
                num++;
        int newLen = length+num*2;
        string[newLen]=0;
        int j=1;
        for(int i=length-1;i>=0;--i)
        {
            if(string[i]!=' ')
            {
                string[newLen-j]=string[i];
                ++j;
            }
            else
            {
                string[newLen-j]='0';
                ++j;
                string[newLen-j]='2';
                ++j;
                string[newLen-j]='%';
                ++j;
            }
        }
        return newLen;
    }
};  
