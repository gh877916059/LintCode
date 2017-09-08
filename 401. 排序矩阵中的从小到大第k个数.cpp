class Solution 
{  
public:  
    int kthSmallest(vector<vector<int> > &matrix, int k) 
    {  
        int n = matrix.size();  
        int m = matrix[0].size();  
        priority_queue<pair<int,pair<int,int> >,vector<pair<int,pair<int,int> > >,greater<pair<int,pair<int,int>> >> q;  
        map<pair<int,int>,bool> visited;  
        q.push(make_pair(matrix[0][0],make_pair(0,0)));  
        visited[make_pair(0,0)]=true;  
        while(k--)  
        {  
            pair<int,pair<int,int> > cur = q.top();  
            if(k==0)  
                return cur.first;  
            q.pop();  
            if(cur.second.first+1<n&&visited[make_pair(cur.second.first+1,cur.second.second)]==false)  
            {  
                q.push(make_pair(matrix[cur.second.first+1][cur.second.second],make_pair(cur.second.first+1,cur.second.second)));  
                visited[make_pair(cur.second.first+1,cur.second.second)]=true;  
            }  
            if(cur.second.second+1<m&&visited[make_pair(cur.second.first,cur.second.second+1)]==false)  
            {  
                q.push(make_pair(matrix[cur.second.first][cur.second.second+1],make_pair(cur.second.first,cur.second.second+1)));  
                visited[make_pair(cur.second.first,cur.second.second+1)]=true;  
            }  
        }  
    }  
};  
