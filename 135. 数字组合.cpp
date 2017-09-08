class Solution 
{
public:
    map<vector<int>,bool> check ;  
    void backtracing(vector<vector<int> > &ret,vector<int> &vec,vector<int> &can,int cur,int n,int left)
    {  
        if(0==left)
        {  
            if(0==check.count(vec))
            {  
                ret.push_back(vec);  
                check[vec]=true;  
            }  
            return ;  
        }      
        for(int i=cur;i<n;++i)
        {  
            if(can[i]<=left)
            {  
                vec.push_back(can[i]);  
                backtracing(ret,vec,can,i,n,left-can[i]);  
                vec.pop_back();  
            }
            else  
                break;  
        }  
    }   
    vector<vector<int> > combinationSum(vector<int> &candidates, int target) 
    {  
        vector<vector<int> > ret;  
        vector<int> vec;  
        int n;  
        if((n=candidates.size())==0)  
            return ret;  
        sort(candidates.begin(),candidates.end());  
        backtracing(ret,vec,candidates,0,n,target);  
        return ret;  
    }  
};
