class Solution 
{
public:
    vector<int> v;
    void process(const vector<NestedInteger> &nestedList, vector<int> &v)
    {
        int len = nestedList.size();
        if (len == 0) 
            return;
        for (int i=0; i<len ; i++) 
        {
            if (nestedList[i].isInteger()) 
                v.push_back(nestedList[i].getInteger());
            else 
                process(nestedList[i].getList(),v);
        }
    };
    vector<int> flatten(vector<NestedInteger> &nestedList) 
    {
        process(nestedList,v);
        return v;
    }
};
