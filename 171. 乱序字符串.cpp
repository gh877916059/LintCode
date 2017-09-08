class Solution 
{  
public:      
    vector<string> anagrams(vector<string> &strs) 
    {  
        map<string,int> m;  
        for(auto s:strs)  
        {  
            sort(s.begin(),s.end());  
            m[s]++;  
        }  
        vector<string> ret;  
        for(auto s:strs)  
        {  
            auto temp = s;  
            sort(temp.begin(),temp.end());  
            if(m[temp]>1)  
                ret.push_back(s);  
        }  
        return ret;  
    }  
}; 
