class Solution {  
public:  
    vector<vector<int> > kSumII(vector<int> A, int k, int target) 
    {  
        vector<int> cur;  
        vector<vector<int> > ret;  
        deal(A,0,k,target,0,cur,ret);  
        return ret;  
    }  
    void deal(vector<int>& A,int index,int k,int target,int sum,vector<int> cur,vector<vector<int> > &ret)  
    {  
        if(cur.size()==k&&sum==target)  
        {  
            ret.push_back(cur);  
            return;  
        }  
        if(index==A.size())  
            return;  
        if(sum>target)  
            return;  
        cur.push_back(A[index]);  
        deal(A,index+1,k,target,sum+A[index],cur,ret);  
        cur.pop_back();  
        deal(A,index+1,k,target,sum,cur,ret);  
    }  
};  
