string toString(int x)
{
	string str;
	if (x == 0)
		return "0";
	while (x > 0)
	{
		str = (char)(x % 10 + '0') + str;
		x /= 10;
	}
	return str;
}
bool cmp(string s1,string s2)  
{  
    string s1s2=s1+s2;
    string s2s1=s2+s1;
    return s1s2>s2s1;
}  
class Solution {  
public:  
    string largestNumber(vector<int> &num) 
    {  
        int sum  = accumulate(num.begin(),num.end(),0);  
        if(sum==0)  
            return "0";  
        vector<string> nums;  
        for(int i=0;i<num.size();i++)  
        {  
            nums.push_back(toString(num[i]));  
        }  
        sort(nums.begin(),nums.end(),cmp);  
        string ret = "";  
        for(int i=0;i<nums.size();i++)  
            ret+=nums[i];  
        return ret;  
    }  
};  
