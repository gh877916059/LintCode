class Solution 
{
public:
    bool isValidParentheses(string& s) 
    {
        stack<char> stack;
        for(int i=0;i<s.length();++i)
        {
            char temp=s[i];
            if(temp=='('||temp=='['||temp=='{')
            {
                stack.push(temp);
            }
            else if(temp==')'||temp==']'||temp=='}')
            {
                char pi_pei;
                if(temp==')')
                    pi_pei='(';
                else if(temp==']')
                    pi_pei='[';
                else
                    pi_pei='{';
                if(stack.top()!=pi_pei)
                    return false;
                stack.pop();
            }
        }
        if(stack.empty())
            return true;
        else
            return false;
    }
};
