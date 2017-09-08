import java.util.Collections;
import java.util.ArrayList;
import java.util.TreeMap;
public class Solution 
{
    public ArrayList<ArrayList<Integer>> threeSum(int[] numbers) 
    {
        ArrayList<ArrayList<Integer>> result = new ArrayList<ArrayList<Integer>>();
        ArrayList<Integer> yu_chu_li = new ArrayList<Integer>();
        TreeMap<String,Boolean> map = new TreeMap<String,Boolean>();
        for(int i=0;i<numbers.length;++i)
            yu_chu_li.add(numbers[i]);
        Collections.sort(yu_chu_li);
        for(int i=0;i<numbers.length;++i)
            numbers[i]=yu_chu_li.get(i);
        for(int min=0;min<numbers.length;++min)
        {
            int mid=min+1;
            int max=numbers.length-1;
            while(mid<max)
            {
                if(numbers[mid]+numbers[max]==-numbers[min])
                {
                    ArrayList<Integer> wow = new ArrayList<Integer>();
                    wow.add(numbers[min]);
                    wow.add(numbers[mid]);
                    wow.add(numbers[max]);
                    String key = ""+numbers[min]+"_"+numbers[mid]+"_"+numbers[max];
                    if(map.get(key)==null)
                    {
                        result.add(wow);
                        map.put(key,Boolean.valueOf(true));
                    }
                    ++mid;
                    --max;
                }
                else if(numbers[mid]+numbers[max]<-numbers[min])
                    ++mid;
                else
                    --max;
            }
        }
        return result;
    }
}
