class Solution 
{
public:
    bool validTree(int n, vector<vector<int>>& edges) 
    {
        vector<vector<int>> neighbor(n);
        for (auto i: edges)
        {
            neighbor[i[0]].push_back(i[1]);
            neighbor[i[1]].push_back(i[0]);
        }
        vector<bool> visited(n, false);
        if (hasCycle(neighbor, visited, -1, 0))
            return false;
        for (auto i: visited)
            if(!i)
                return false;
        return true;
    }
    bool hasCycle(vector<vector<int>> &neighbor, vector<bool> &visited, int par, int kid)
    {
        if (visited[kid])
            return true;
        visited[kid] = true;
        for (auto i: neighbor[kid])
        {
            if (par != i && hasCycle(neighbor, visited, kid, i))
                return true;
        }
        return false;
    }
};
