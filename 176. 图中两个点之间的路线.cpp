class Solution 
{  
public:  
    bool hasRoute(vector<DirectedGraphNode*> graph,  
                  DirectedGraphNode* s, DirectedGraphNode* t) 
                  {  
        queue<DirectedGraphNode*> q;  
        map<DirectedGraphNode*,bool> visited;  
        q.push(s);  
        visited[s]=true;  
        while(!q.empty())  
        {  
            DirectedGraphNode* cur = q.front();  
            q.pop();  
            if(cur==t)  
                return true;  
            for(auto neighbour:cur->neighbors)  
            {  
                if(!visited[neighbour])  
                {  
                    q.push(neighbour);  
                    visited[neighbour]=true;  
                }  
            }  
        }  
        return false;  
    }  
};  
