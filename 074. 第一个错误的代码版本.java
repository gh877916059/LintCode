class Solution 
{
    public int findFirstBadVersion(int n) 
    {
        int x=1;
        int y=n;
        int m;
        while(x<y)
        {
            m=x+(y-x)/2;
            if(SVNRepo.isBadVersion(m))
                y=m;
            else
                x=m+1;
        }
        return x;
    }
}
