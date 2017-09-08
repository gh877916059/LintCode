public class Solution 
{  
    public int searchMatrix(int[][] matrix, int target) 
    {  
        if(matrix==null || matrix.length==0)
        {  
            return 0;  
        }  
        int count=0;  
        int row=matrix.length-1;  
        int col=0;  
        while(row>=0 && col<=matrix[0].length-1)
        {  
            if(target==matrix[row][col])
            {  
                count++;  
                row--;  
                col++;  
            }
            else if(matrix[row][col]<target)
            {  
                col++;  
            }
            else
            {  
                row--;  
            }  
        }  
        return count;  
    }  
}  
