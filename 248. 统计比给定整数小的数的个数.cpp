class Solution {  
public:  
    vector<int> countOfSmallerNumber(vector<int> &A, vector<int> &queries) 
    {  
        sort(A.begin(),A.end());  
        vector<int> ret;  
        for(int q:queries)  
        {  
            int cnt = lower_bound(A.begin(),A.end(),q)-A.begin();  
            ret.push_back(cnt);  
        }  
        return ret;  
    }  
};  
