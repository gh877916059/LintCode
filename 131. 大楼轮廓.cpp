struct JUMP  
{  
    int index; 
    int height;  
    JUMP(int a, int b) : index(a), height(b){}
    bool operator< (const JUMP &j)  const  
    {
        if(index != j.index)
            return index < j.index;
        else
            return height > j.height;
    }
}; 
class Solution 
{
public:
    vector<vector<int> > buildingOutline(vector<vector<int> > &buildings) 
    {
        int numOfBuilding = buildings.size();
        int sizeOfJumps = numOfBuilding * 2;
        vector<JUMP> jumps;
        for(int i = 0; i < numOfBuilding; i++)
        {
            jumps.push_back(JUMP(buildings[i][0], buildings[i][2]));
            jumps.push_back(JUMP(buildings[i][1], - buildings[i][2]));
        }
        sort(jumps.begin(), jumps.end());
        vector<vector<int>> result;
        multiset<int> current;
        int prevJump = 0;
        for(int i = 0; i < sizeOfJumps; i++)
        {
            if(current.empty())
            {
                current.insert(jumps[i].height);
                prevJump = jumps[i].index;
                continue;
            }
            if(jumps[i].height > 0)
            {
                if(jumps[i].height > *current.rbegin())
                {
                    vector<int> jump;
                    jump.push_back(prevJump);
                    jump.push_back(jumps[i].index);
                    jump.push_back(*current.rbegin());
                    result.push_back(jump);
                    prevJump = jumps[i].index;
                }
                current.insert(jumps[i].height);
            }
            else
            {
                if(jumps[i].height == -*current.rbegin() 
                && current.count(-jumps[i].height) < 2)
                {
                    vector<int> jump;
                    jump.push_back(prevJump);
                    jump.push_back(jumps[i].index);
                    jump.push_back(*current.rbegin());
                    result.push_back(jump);
                    prevJump = jumps[i].index;
                }
                current.erase(current.lower_bound(-jumps[i].height));
            }
        }
        return result;
    }
};
