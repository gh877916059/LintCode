class Solution 
{
public:
    int lengthOfLastWord(string& s) 
    {
        int index =s.length()-1;
        for(;index>=0;--index)
        {
            if(s[index]!=' ')
                break;
        }
        if(index<0)
            return 0;
        int counter=0;
        for(;index>=0;--index)
        {
            ++counter;
            if(s[index]==' ')
            {
                --counter;
                break;
            }
        }
        return counter;
    }
};
