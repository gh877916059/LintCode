class Solution 
{  
public:  
    string simplifyPath(string& path) 
    {  
        stack<string> st;  
        string cur = "";  
        path+="/";  
        for(int i=0;i<path.length();i++)  
        {  
            if(path[i]=='/')  
            {  
                if(cur=="..")  
                {  
                    if(!st.empty())  
                        st.pop();  
                }  
                else if(cur=="."){}  
                else if(cur.length()>0)  
                {  
                    st.push(cur);  
                }  
                cur = "";  
            }  
            else  
                cur+=path[i];  
        }  
        string ret = "";  
        while(!st.empty())  
        {  
            ret = "/"+st.top()+ret;  
            st.pop();  
        }  
        if(ret.length()==0)  
            ret = "/";  
        return ret;  
    }  
};  
