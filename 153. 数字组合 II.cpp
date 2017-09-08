class Solution 
{
public:
vector<vector<int> > result;
vector<int> cur;
int cur_sum=0;
    vector<vector<int> > combinationSum2(vector<int> &num, int target) 
    {
        if(num.size()==0)
            return result;
        sort(num.begin(),num.end());
        diGui(num,target,0);
        return result;
    }
    void diGui(vector<int> &num,int target,int pos)
    {
        for(int i=pos;i<num.size();++i)
        {
            if(i==pos||num[i-1]!=num[i])
            {
                if(cur_sum+num[i]<=target)
                {
                    cur_sum+=num[i];
                    cur.push_back(num[i]);
                    if(cur_sum==target)
                    {
                        result.push_back(cur);
                    }
                    diGui(num,target,i+1);
                    cur_sum-=num[i];
                    cur.pop_back();
                }
            }
        }
    }
};
