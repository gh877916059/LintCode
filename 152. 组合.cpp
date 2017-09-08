class Solution 
{
public:
    void backtracing(vector<vector<int> > &ret,vector<int> &tmp,int cur,int n,int k)
    {  
        if(tmp.size()==k)
        {  
            ret.push_back(tmp);  
            return ;  
        }  
        if(cur>n)  
            return ;  
        tmp.push_back(cur);  
        backtracing(ret,tmp,cur+1,n,k);  
        tmp.pop_back();  
        backtracing(ret,tmp,cur+1,n,k);  
    }        
    vector<vector<int> > combine(int n, int k) 
    {  
        vector<vector<int> > ret;  
        vector<int> tmp;  
        backtracing(ret,tmp,1,n,k);  
        return ret;  
    }  
};
