import java.util.Collections;
import java.util.ArrayList;
public class Solution 
{
    public ArrayList<ArrayList<Integer>> fourSum(int[] numbers, int target) 
    {
        quick_sort(numbers);
        ArrayList<ArrayList<Integer>> result = new ArrayList<ArrayList<Integer>>();
        for(int a=0;a<numbers.length;++a)
        {
            for(int b=a+1;b<numbers.length;++b)
            {
                int c=b+1;
                int d=numbers.length-1;
                int target2 = target-numbers[a]-numbers[b];
                while(c<d)
                {
                    int yuan_c = numbers[c];
                    int yuan_d = numbers[d];
                    if(numbers[c]+numbers[d]==target2)
                    {
                        ArrayList<Integer> temp = new ArrayList<Integer>();
                        temp.add(numbers[a]);
                        temp.add(numbers[b]);
                        temp.add(numbers[c]);
                        temp.add(numbers[d]);
                        result.add(temp);
                        ++c;
                        --d;
                        while(c<numbers.length&&yuan_c==numbers[c])
                            ++c;
                        while(d<numbers.length&&yuan_d==numbers[d])
                            --d;
                    }
                    else if(numbers[c]+numbers[d]<target2)
                    {
                        ++c;
                        while(c<numbers.length&&yuan_c==numbers[c])
                            ++c;
                    }
                    else
                    {
                        --d;
                        while(d<numbers.length&&yuan_d==numbers[d])
                            --d;
                    }
                }
                while((b+1)<numbers.length&&numbers[b]==numbers[b+1])
                    ++b;
            }
            while((a+1)<numbers.length&&numbers[a]==numbers[a+1])
                ++a;
        }
        return result;
    }
    public void quick_sort(int[] numbers)
    {
        quick_sort(numbers,0,numbers.length-1);
    }
    public void quick_sort(int[] numbers,int start,int end)
    {
        if(start>=end)
            return;
        int mid = select(numbers,start,end);
        quick_sort(numbers,start,mid-1);
        quick_sort(numbers,mid+1,end);
    }
    public int select(int[] numbers,int start,int end)
    {
        int ji_zhun = numbers[end];
        int index = start-1;
        int temp;
        for(int i=start;i<end;++i)
        {
            if(numbers[i]<ji_zhun)
            {
                ++index;
                temp = numbers[index];
                numbers[index] = numbers[i];
                numbers[i] = temp;
            }
        }
        ++index;
        temp = numbers[index];
        numbers[index] = numbers[end];
        numbers[end] = temp;
        return index;
    }
}
