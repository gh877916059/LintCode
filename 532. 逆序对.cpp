class Solution 
{
public:
    int count=0;
    long long reversePairs(vector<int>& A) 
    {
        mergeSort(A);
        return count;
    }
    void mergearray(vector<int>& a,int first,int mid,int last,vector<int>& temp)
    {
        int i=first,j=mid+1;
        int m=mid,n=last;
        int k=0;
        while(i<=m&&j<=n)
        {
            if(a[i]>a[j])
            {
                temp[k++]=a[j++];
                count+=mid-i+1;
            }
            else
                temp[k++]=a[i++];
        }
        while(i<=m)
            temp[k++]=a[i++];
        while(j<=n)
            temp[k++]=a[j++];
        for(i=0;i<k;i++)
            a[first+i]=temp[i];
    }
    void mergesort(vector<int>& a,int first,int last,vector<int>& temp)
    {
        if(first<last)
        {
            int mid=(first+last)/2;
            mergesort(a,first,mid,temp);
            mergesort(a,mid+1,last,temp);
            mergearray(a,first,mid,last,temp);
        }
    }
    void mergeSort(vector<int>& a)
    {
        vector<int> p(a.size(),0);
        mergesort(a,0,a.size()-1,p);
    }
};
