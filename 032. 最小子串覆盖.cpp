class Solution {  
public:  
    string minWindow(string &source, string &target) 
    {  
        if (source.empty() || target.empty())  
            return "";  
        int sLen = source.length(), tLen = target.length();  
        vector<int> sHash(256, 0), tHash(256, 0);  
        for (int i = 0; i < tLen; ++i)  
        {  
            ++tHash[target[i]];  
        } 
        int beg = -1, end = sLen, found = 0, minLen = sLen;  
        for (int i = 0, start = i; i < sLen; ++i)  
        {  
            ++sHash[source[i]];  
            if (sHash[source[i]] <= tHash[source[i]])  
                ++found;  
            if (found == tLen)  
            {  
                while (start < i && sHash[source[start]] > tHash[source[start]])  
                {  
                    --sHash[source[start]];  
                    ++start;  
                }  
                if (i - start < minLen)  
                {  
                    minLen = i - start;  
                    beg = start;  
                    end = i;  
                }
                --sHash[source[start++]];  
                --found;  
            } 
        }
        if (beg == -1)  
            return "";  
        else  
            return source.substr(beg, end - beg + 1);  
    }  
};  
