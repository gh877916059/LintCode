import java.util.ArrayList;
public class Solution 
{
    public ArrayList<Long> productExcludeItself(ArrayList<Integer> A) 
    {
        ArrayList<Long> result = new ArrayList<Long>();
        for(int i=0;i<A.size();++i)
        {
            long temp=1;
            for(int j=0;j<A.size();++j)
            {
                if(i!=j)
                {
                    temp*=A.get(j);
                }
            }
            result.add(new Long(temp));
        }
        return result;
    }
}
