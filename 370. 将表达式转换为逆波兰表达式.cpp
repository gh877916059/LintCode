class Solution 
{
public:
    unordered_map<string,int> you_xian_ji;
    int StrToInt(string str)
    {
        stringstream ss(str);
        int result;
        ss>>result;
        return result;
    }
    string IntToStr(int num)
    {
        string str;
        stringstream ss;
        ss<<num;
        str=ss.str();
        return str;
    }
    bool isShu(string str)
    {
        if(str[0]>='0'&&str[0]<='9')
            return true;
        if(str[0]=='-'&&str.length()>1)
            return true;
        return false;
    }
    vector<string> convertToRPN(vector<string> &expression) 
    {
        vector<string> hou_expression;
        if(expression.size()==0)
            return hou_expression;
        stack<string> stack;
        you_xian_ji["+"]=1;
        you_xian_ji["-"]=1;
        you_xian_ji["*"]=2;
        you_xian_ji["/"]=2;
        for(auto i:expression)
        {
            if(isShu(i))
                hou_expression.push_back(i);
            else if(i=="(")
                stack.push(i);
            else if(i==")")
            {
                while(stack.top()!="(")
                {
                    hou_expression.push_back(stack.top());
                    stack.pop();
                }
                stack.pop();
            }
            else
            {
                while(true)
                {
                    if(stack.empty())
                    {
                        stack.push(i);
                        break;
                    }
                    else if(stack.top()=="(")
                    {
                        stack.push(i);
                        break;
                    }
                    else if(you_xian_ji[i]>you_xian_ji[stack.top()])
                    {
                        stack.push(i);
                        break;
                    }
                    else
                    {
                        hou_expression.push_back(stack.top());
                        stack.pop();
                    }
                }
            }
        }
        while(!stack.empty())
        {
            hou_expression.push_back(stack.top());
            stack.pop();
        }
        return hou_expression;
    }
};
