class WordCountMapper: public Mapper 
{  
public:  
    void Map(Input<string>* input) 
    {  
        vector<string> vecStr;  
        while(!input->done())
        {  
            string str = input->value();  
            int j =0;  
            for(int i = 0; i<=str.size(); i++)
            {  
                if (str[i] == ' '||i == str.size())
                {  
                    string temp = str.substr(j,i-j);  
                    output(temp,1);  
                    j = i+1;  
                }  
            }  
            input->next();  
        }  
    }  
};  
  
  
class WordCountReducer: public Reducer 
{  
public:  
    void Reduce(string &key, Input<int>* input) 
    {  
        int sum = 0;  
        while(!input->done()) 
        {  
            sum += input->value();  
            input->next();  
        }  
        output(key, sum);  
    }  
};  
