class Solution 
{  
public:  
    vector<int> numbersByRecursion(int n) 
    {  
        vector<int> ret;  
        if(n<=0)  
            return ret;  
        else if(n==1)  
        {  
            ret = {1,2,3,4,5,6,7,8,9};  
            return ret;  
        }  
        else  
        {  
            vector<int> temp = numbersByRecursion(n-1);  
            copy(temp.begin(),temp.end(),back_inserter(ret));  
            for(int i=1;i<=9;i++)  
            {  
                ret.push_back(pow(10,n-1)*i);  
                for(auto x:temp)  
                {  
                    ret.push_back(pow(10,n-1)*i+x);  
                }  
            }  
            return ret;  
        }  
    }  
};  
