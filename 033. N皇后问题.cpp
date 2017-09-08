class Solution {  
public:  
    vector<vector<string> > solveNQueens(int n) 
    {  
        vector<int> queen(n,-1);  
        stack<int> st;  
        st.push(0);  
        vector<vector<string> > ret;  
        while(!st.empty())  
        {  
            int row = st.top();  
            queen[row]++;  
            if(queen[row]>=n)  
                st.pop();  
            else  
            {  
                if(verify(queen,row))  
                {  
                    if(row==n-1)  
                    {  
                        vector<string> v;  
                        for(int i=0;i<n;i++)  
                        {  
                            int x = queen[i];  
                            string s = "";  
                            for(int j=0;j<n;j++)  
                            {  
                                if(j==x)  
                                    s+='Q';  
                                else  
                                    s+='.';  
                            }  
                            v.push_back(s);  
                        }  
                        ret.push_back(v);  
                    }  
                    else  
                    {  
                        queen[row+1]=-1;  
                        st.push(row+1);  
                    }  
                }  
            }  
        }  
        return ret;  
    }  
    bool verify(vector<int> queen,int row)  
    {  
        for(int i=0;i<=row;i++)  
        {  
            for(int j=0;j<i;j++)  
                if(queen[i]==queen[j]||(abs(queen[i]-queen[j])==i-j))  
                    return false;  
        }  
        return true;  
    }  
};  
