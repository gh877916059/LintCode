class Solution
{
public:
	int maximalRectangle(vector<vector<bool> > &matrix)
	{
	    int n=matrix.size();
	    if(n==0)
	        return 0;
	    int m=matrix[0].size();
	    int result=0;
	    vector<int> height(m,0);
	    for(int j=0;j<m;++j)
	    {
	        height[j]=matrix[0][j];
	        result=max(result,largestRectangleArea(height));
	    }
	    for(int i=1;i<n;++i)
	    {
	        for(int j=0;j<m;++j)
	        {
	            if(matrix[i][j]==0)
	                height[j]=0;
	            else
	                ++height[j];
	        }
	        result=max(result,largestRectangleArea(height));
	    }
	    return result;
	}
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
