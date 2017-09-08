class Solution 
{  
public:  
    void subsetsWithDup(vector<int> &S,int pos)
    {  
        result.push_back(base);       
        for(int i=pos;i<size;++i)
        {  
            if(i!=pos&&S[i]==S[i-1])   
                continue;             
            base.push_back(S[i]);  
            subsetsWithDup(S,i+1);  
            base.pop_back();  
        }  
    }  
    vector<vector<int> > subsetsWithDup(const vector<int> &S1) 
    {  
        if(S1.empty())  
            return result;  
        vector<int> S(S1);  
        size=S.size();      
        sort(S.begin(),S.end());   
        subsetsWithDup(S,0);  
        return result;  
    }  
private:  
        int size;  
        vector<vector<int> > result;  
        vector<int>            base;    
};
