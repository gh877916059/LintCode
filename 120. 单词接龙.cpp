class Solution
{
public:
	unordered_map<string, bool> check;
	int ladderLength(string start, string end, unordered_set<string> &dict)
	{
		if (start.length() != end.length())
			return -1;
		int result = 0;
		dict.insert(start);
		dict.insert(end);
		for (auto i : dict)
		{
			if (i.length() == start.length())
			{
				check[i] = false;
			}
			else
			{
				dict.erase(i);
			}
		}
		queue<string> Q;
		Q.push(start);
		check[start]=true;
		int counter1=1;
		int counter2=0;
		bool zhao_dao=false;
		while(!Q.empty())
		{
		    while(counter1-->0)
		    {
		        string temp = Q.front();
		        Q.pop();
		        if(temp==end)
		        {
		            zhao_dao=true;
		            break;
		        }
		        for(int i=0;i<temp.length();++i)
		        {
		            for(char j='a';j<='z';++j)
		            {
		                if(temp[i]!=j)
		                {
		                    string temp2=temp.substr(0,i)+j+temp.substr(i+1);
		                    if(dict.find(temp2)!=dict.end()&&!check[temp2])
		                    {
		                        Q.push(temp2);
		                        check[temp2]=true;
		                        ++counter2;
		                    }
		                }
		            }
		        }
		    }
		    if(zhao_dao)
		        break;
		    counter1=counter2;
		    counter2=0;
		    ++result;
		}
		if(zhao_dao)
		    return result+1;
		else
		    return -1;
	}
};
