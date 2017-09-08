class Solution 
{  
public:  
    char *m_pData;  
    Solution() 
    {  
        this->m_pData = NULL;  
    }  
    Solution(char *pData) 
    {  
        this->m_pData = pData;  
    }  
    Solution operator=(const Solution &object) 
    {  
        if(this==&object)  
            return *this;  
        if(m_pData&&*m_pData)  
            delete m_pData;  
        if(object.m_pData==nullptr)  
        {  
            m_pData = nullptr;  
            return *this;  
        }  
        m_pData = new char[strlen(object.m_pData)+1];  
        strcpy(object.m_pData,m_pData);  
        m_pData[strlen(object.m_pData)]='\0';  
        return *this;  
    }  
};  
