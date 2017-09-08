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
class Solution
{
public:
	string minNumber(vector<int>& nums)
	{
		vector<string> nums_s;
		for (int i = 0; i<nums.size(); i++)
		{
		    if(nums[i]!=0)
			    nums_s.push_back(toString(nums[i]));
		}
		sort(nums_s.begin(), nums_s.end(), cmp);
		reverse(nums_s.begin(), nums_s.end());
		string ret = "";
		for (int i = 0; i<nums_s.size(); i++)
			ret += nums_s[i];
		if(ret=="")
		    return "0";
		return ret;
	}
};
