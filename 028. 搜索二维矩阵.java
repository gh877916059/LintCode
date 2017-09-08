public class Solution 
{
    public boolean searchMatrix(int[][] matrix, int target) 
    {
        int hang = matrix.length;
        if(hang==0)
            return false;
        int lie = matrix[0].length;
        if(lie==0)
            return false;
        int x = 0;
        int y = hang;
        int m;
        while(x<y)
        {
            m = x+(y-x)/2;
            if(matrix[m][lie-1]<target)
                x=m+1;
            else
                y=m;
        }
        if(x>=hang)
            return false;
        if(matrix[x][lie-1]==target)
            return true;
        else
        {
            int hang_yes=x;
            x=0;
            y=lie;
            while(x<y)
            {
                m=x+(y-x)/2;
                if(matrix[hang_yes][m]<target)
                    x=m+1;
                else
                    y=m;
            }
            if(x>=lie)
                return false;
            if(matrix[hang_yes][x]==target)
                return true;
        }
        return false;
    }
}
