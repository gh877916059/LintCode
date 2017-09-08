class Solution 
{
public:
    vector<DirectedGraphNode*> topSort(vector<DirectedGraphNode*> graph)
    {
        vector<DirectedGraphNode*> ret;  
        if(graph.empty())  
            return ret;  
          
        map<DirectedGraphNode*,int> in; 
        stack<DirectedGraphNode*>   s; 
        for(auto e:graph){  
            for(auto i:e->neighbors)  
                ++in[i];
        }  
        for(auto e:graph)  
           if(0==in[e])  
               s.push(e);
        while(!s.empty())
        {
            DirectedGraphNode* cur=s.top();  
            s.pop(); 
            ret.push_back(cur);     
            for(auto e:cur->neighbors)
            {  
                if(--in[e]==0)
                    s.push(e);  
            }  
        }         
        return ret;  
    }
};
