class Solution 
{  
public:  
    void heapify(vector<int> &A) 
    {  
        int n = A.size()-1;  
        for(int i=n/2;i>=0;i--)  
            heapify(A,i);  
    }  
    void heapify(vector<int> &A,int i)  
    {  
        int l = 2*i+1;  
        int r = 2*i+2;  
        int smallest = i;  
        if(l<A.size()&&A[l]<A[smallest])  
            smallest = l;  
        if(r<A.size()&&A[r]<A[smallest])  
            smallest = r;  
        if(smallest!=i)  
        {  
            swap(A[i],A[smallest]);  
            heapify(A,smallest);  
        }  
    }  
};  
