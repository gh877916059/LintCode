class NestedIterator 
{
public:
    queue<int> v;
    NestedIterator(vector<NestedInteger> &nestedList) 
    {
        process(nestedList,v);
    }
    void process(const vector<NestedInteger> &nestedList, queue<int> &v)
    {
        int len = nestedList.size();
        if (len == 0) 
            return;
        for (int i=0; i<len ; i++) 
        {
            if (nestedList[i].isInteger()) 
                v.push(nestedList[i].getInteger());
            else 
                process(nestedList[i].getList(),v);
        }
    };
    int next() 
    {
        int temp = v.front();
        v.pop();
        return temp;
    }
    bool hasNext() {
        if (!v.empty()) 
            return true;
        return false;
    }
};
