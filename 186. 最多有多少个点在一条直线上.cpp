class Solution 
{
public:
    int maxPoints(vector<Point>& points) 
    {
        int n=points.size();
        if(n==0)
            return 0;
        unordered_map<double,int> map;
        int result=0;
        for(int i=0;i<n;++i)
        {
            map.clear();
            map[(double)INT_MIN]=1;
            int dup=0;
            for(int j=i+1;j<n;++j)
            {
                if(points[j].x==points[i].x&&points[j].y==points[i].y)
                {
                    dup++;
                    continue;
                }
                double key=points[j].x-points[i].x==0?INT_MAX:0.0+(double)(points[j].y - points[i].y) / (double)(points[j].x - points[i].x);
                if(map.find(key)!=map.end())
                {
                    ++map[key];
                }
                else
                    map[key]=2;
            }
            for(auto temp:map)
            {
                if(temp.second+dup>result)
                    result=temp.second+dup;
            }
        }
        return result;
    }
};
