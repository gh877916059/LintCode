public class Solution 
{
    public int canCompleteCircuit(int[] gas, int[] cost) 
    {
        int cur = 0;  
        int totalGas = 0;  
        int totalCost = 0;  
        int start = 0;  
        for(int i=0;i<gas.length;i++)  
        {  
            cur+=gas[i];  
            cur-=cost[i];  
            totalGas+=gas[i];  
            totalCost+=cost[i];  
            if(cur<0)  
            {  
                start = i+1;  
                cur = 0;  
            }  
        }  
        if(totalGas>=totalCost)  
            return start;  
        return -1;  
    }
}
