public class Solution 
{
    public String binaryRepresentation(String n) 
    {
        char[] n_s = n.toCharArray();
        int dian = n_s.length;
        for(int i=0;i<n_s.length;++i)
        {
            if(n_s[i]=='.')
                dian = i;
        }
        long ji_shu = 1;
        long zheng = 0;
        for(int i=dian-1;i>=0;--i)
        {
            zheng+=ji_shu*(n_s[i]-'0');
            ji_shu*=10;
        }
        String result = "";
        if(zheng==0)
            result+="0";
        while(zheng>0)
        {
            result += zheng%2;
            zheng/=2;
        }
        char[] result_s = result.toCharArray();
        result="";
        for(int i=result_s.length-1;i>=0;--i)
        {
            result+=result_s[i];
        }
        if(dian==n_s.length)
            return result;
        else
        {
            ji_shu = 1;
            zheng = 0;
            for(int i=n_s.length-1;i>dian;--i)
            {
                zheng += ji_shu*(n_s[i]-'0');
                ji_shu*=10;
            }
            int counter=0;
            if(zheng>0)
                result+=".";
            while(zheng>0)
            {
                zheng*=2;
                if(zheng>=ji_shu)
                {
                    result+="1";
                    zheng%=ji_shu;
                }
                else
                {
                    result+="0";
                }
                ++counter;
                if(counter>32)
                {
                    result="ERROR";
                    break;
                }
            }
            return result;
        }
    }
}
