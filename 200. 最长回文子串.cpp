class Solution 
{  
public:  
    string longestPalindrome(string& s) 
    {  
        string news = "$#";  
        for(int i=0;i<s.length();i++)  
        {  
            news+=s[i];  
            news+="#";  
        }  
        vector<int> p(news.length(),0);  
        int mx = 0;  
        int id = 0;  
        int retid = 0;  
        int maxp = 0;  
        for(int i=0;i<news.length();i++)  
        {  
            if(mx>i)  
            {  
                p[i] = min(mx-i+1,p[2*id-i]);  
            }  
            else  
                p[i] = 1;  
            while(i-p[i]>=0&&news[i+p[i]]==news[i-p[i]])  
                p[i]++;  
            if(i+p[i]-1>mx)  
            {  
                mx = i+p[i]-1;  
                id = i;  
            }  
            if(p[i]>maxp)  
            {  
                maxp = p[i];  
                retid = i;  
            }  
        }  
        string ret = "";  
        for(int i=retid-p[retid]+1;i<=retid+p[retid]-1;i++)  
            if(news[i]!='#')  
                ret+=news[i];  
        return ret;  
    }  
};  
