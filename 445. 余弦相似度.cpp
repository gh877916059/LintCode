class Solution 
{
public:
    double cosineSimilarity(vector<int> A, vector<int> B) 
    {
        if(A.size()!=B.size())
            return 2.0;
        if(A.size()==0)
            return 2.0;
        double fenzi=0.0;
        double fenmu1=0.0;
        double fenmu2=0.0;
        int n=A.size();
        for(int i=0;i<n;++i)
        {
            fenzi+=A[i]*B[i];
            fenmu1+=A[i]*A[i];
            fenmu2+=B[i]*B[i];
        }
        fenmu1=sqrt(fenmu1);
        fenmu2=sqrt(fenmu2);
        if(fenmu1==0||fenmu2==0)
            return 2.0;
        fenzi/=fenmu1;
        fenzi/=fenmu2;
        return fenzi;
    }
};
