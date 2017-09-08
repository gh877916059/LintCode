class Queue {
public:
    stack<int> stack1;
    stack<int> stack2;
    Queue() 
    {
    }
    void push(int element) 
    {
        stack1.push(element);
    }
    int pop() 
    {
        int data;
        if(stack2.empty())
        {
            while(!stack1.empty())
            {
                data = stack1.top();
                stack1.pop();
                stack2.push(data);
            }
        }
        data = stack2.top();
        stack2.pop();
        return data;
    }
    int top() 
    {
        int data;
        if(stack2.empty())
        {
            while(!stack1.empty())
            {
                data = stack1.top();
                stack1.pop();
                stack2.push(data);
            }
        }
        data = stack2.top();
        return data;
    }
};
