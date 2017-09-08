class Solution 
{
public:
    int addDigits(int num) 
    {
        if(num<10)
            return num;
        int result=0;
        while(num!=0)
        {
            result+=num;
            num/=10;
        }
        return addDigits(result);
    }
};
