class Solution 
{  
public:  
    int largestRectangleArea(vector<int> &height) 
    {  
        stack<int> stack_;  
        int maxArea = 0;  
        int i = 0;  
        while(i < height.size()) 
        {  
            if(stack_.empty() ||   height[i] >= stack_.top()) 
            {  
                stack_.push(height[i]);  
                i++;  
            }  
            else 
            {  
                int count = 0;  
                while(!stack_.empty() &&   stack_.top() > height[i]) 
                {  
                    count++;  
                    int top = stack_.top();  
                    stack_.pop();  
                    maxArea = max(maxArea, top * count);  
                }  
                for(int j = 0; j < count + 1; ++j) 
                {  
                    stack_.push(height[i]);  
                }  
                i++;  
            }  
        }  
        int count = 0;  
        while(!stack_.empty()) 
        {  
            count++;  
            maxArea = max(maxArea, stack_.top() * count);  
            stack_.pop();  
        }  
        return maxArea;  
    }  
};  
