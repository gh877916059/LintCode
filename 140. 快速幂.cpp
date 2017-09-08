class Solution 
{  
public:  
    int fastPower(int a, int b, int n) 
    {  
        if(n==0)  
            return 1%b;  
        if(n==1)  
            return a%b;  
        long long temp = fastPower(a,b,n/2);  
        if(n&1)  
            return ((temp*temp)%b)*a%b;  
        else  
            return temp*temp%b;  
    }  
};  
