class Solution 
{
public:
    bool isHappy(int n) 
    {
        int temp=n;
        unordered_set<int> hashSet;
        hashSet.insert(temp);
        while(true)
        {
            temp=getNext(temp);
            if(temp==1)
                return true;
            else if(hashSet.count(temp)>0)
                return false;
            hashSet.insert(temp);
        }
    }
    int getNext(int num)
    {
        int result=0;
        while(num>0)
        {
            result+=(num)*(num);
            num/=10;
        }
        return result;
    }
};
