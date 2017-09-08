class Solution 
{  
public:  
    int countOfAirplanes(vector<Interval> &airplanes) 
    {  
        map<int,int> m;  
        set<int> s;  
        for(int i=0;i<airplanes.size();i++)  
        {  
            Interval in = airplanes[i];  
            m[in.start]++;  
            m[in.end]--;  
            s.insert(in.start);  
            s.insert(in.end);  
        }  
        vector<int> t;  
        copy(s.begin(),s.end(),back_inserter(t));
        int ret = 0;  
        int cnt = 0;  
        for(auto x:t)  
        {  
            cnt+=m[x];  
            ret = max(ret,cnt);  
        }  
        return ret;  
    }  
};  
