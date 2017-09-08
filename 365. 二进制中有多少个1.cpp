class Solution 
{
public:
    int countOnes(int num) 
    {
        int counter=0;
        for(int i=0;i<32;++i)
        {
            counter+=(num%2+2)%2;
            num>>=1;
        }
        return counter;
    }
};
