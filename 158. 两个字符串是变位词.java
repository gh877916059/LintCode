
public class Solution
{
    
    public boolean anagram(String s, String t) 
    {
        char[] ss = s.toCharArray();
        char[] ts = t.toCharArray();
        MySort(ss);
        MySort(ts);
        s = String.valueOf(ss);
        t = String.valueOf(ts);
        if(s.equals(t))
            return true;
        else
            return false;
    }
    
    private static void quick_sort(char[] s, int l, int r) 
    {
        if(l>=r)
            return;
        int mid = partition(s,l,r);
        quick_sort(s, l, mid-1);
        quick_sort(s, mid+1, r);
    }
    
    private static int partition(char[] s,int l,int r)
    {
        int i=l-1;
        char standard = s[r];
        char temp;
        for(int j=l;j<r;++j)
        {
            if(s[j]<standard)
            {
                ++i;
                //swap s[i] and s[j]
                temp=s[i];
                s[i]=s[j];
                s[j]=temp;
            }
        }
        //swap s[i+1] and s[r]
        temp=s[i+1];
        s[i+1]=s[r];
        s[r]=temp;
        return i+1;
    }
    
    private static void MySort(char[] data) 
    {
        quick_sort(data, 0, data.length-1);
    }

};
