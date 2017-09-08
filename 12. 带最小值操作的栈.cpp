class MinStack 
{  
public:  
    MinStack() 
    {  
        while(!minnum.empty())
        {  
            minnum.pop();  
        }  
        while(!data.empty())
        {  
            data.pop();  
        }  
    }  
    void push(int number) 
    {  
        if(data.empty())
        {  
            data.push(number);  
            minnum.push(number);  
        }
        else
        {  
            int tmp = minnum.top();  
            data.push(number);  
            if(number < tmp)
                minnum.push(number);  
            else
                minnum.push(tmp); 
        }  
    }  
    int pop() 
    {  
        int tmp = data.top();  
        data.pop();  
        minnum.pop();  
        return tmp;  
    }  
    int min() 
    {  
        int tmp = minnum.top();  
        return tmp;  
    }  
private:  
    stack<int> minnum;  
    stack<int> data;  
};  
