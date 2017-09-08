import java.util.Collections;
import java.util.ArrayList;
import java.util.TreeMap;
public class Solution 
{
    public int[] twoSum(int[] numbers, int target) 
    {
        ArrayList<Pair> list = new ArrayList<Pair>();
        int[] result =new int[2];
        for(int i=0;i<numbers.length;++i)
        {
            list.add(new Pair(i,numbers[i]));
        }
        Collections.sort(list);
        int min=0;
        int max=numbers.length-1;
        while(min<max)
        {
            if(list.get(min).value+list.get(max).value==target)
            {
                if(list.get(min).yuan_lai<list.get(max).yuan_lai)
                {
                result[0]=list.get(min).yuan_lai+1;
                result[1]=list.get(max).yuan_lai+1;                 
                }
                else
                {
                result[0]=list.get(max).yuan_lai+1;
                result[1]=list.get(min).yuan_lai+1;                     
                }
                break;
            }
            else if(list.get(min).value+list.get(max).value<target)
            {
                ++min;
            }
            else
            {
                --max;
            }
        }
        return result;
    }
    class Pair implements Comparable
    {
        int yuan_lai;
        int value;
        public Pair(int a,int b)
        {
            yuan_lai = a;
            value = b;
        }
        public int compareTo(Object other)
        {
            return Integer.valueOf(value).compareTo(Integer.valueOf(((Pair)other).value));
        }
    }
}
