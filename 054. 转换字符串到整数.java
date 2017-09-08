import java.math.BigDecimal;
public class Solution 
{
    public int atoi(String str) 
    {
        int jie_shu = str.length();
        int kai_shi = 0;
        int state = 0;
        for(int i=0;i<str.length();++i)
        {
            switch(state)
            {
                case 0:
                    if(str.charAt(i)==' ')
                        state = 0;
                    else if(str.charAt(i)=='-')
                    {
                        state = 2;
                        kai_shi = i;
                    }
                    else if(str.charAt(i)=='+')
                    {
                        state = 2;
                        kai_shi = i+1;
                    }
                    else if(str.charAt(i)>='0'&&str.charAt(i)<='9')
                    {
                        state = 1;
                        kai_shi = i;
                    }
                    else
                        state = -1;
                    break;
                case 1:
                    if(str.charAt(i)>='0'&&str.charAt(i)<='9')
                        state = 1;
                    else
                    {
                        state = 3;
                        jie_shu = i;
                    }
                    break;
                case 2:
                    if(str.charAt(i)>='0'&&str.charAt(i)<='9')
                        state = 1;
                    else
                        state = -1;
                    break;
            }
        }
        if(state!=1&&state!=3)
            return 0;
        str=str.substring(kai_shi,jie_shu);
        BigDecimal Max = BigDecimal.valueOf(2147483647);
        BigDecimal Min = BigDecimal.valueOf(-2147483648);
        BigDecimal target = new BigDecimal(str);
        BigDecimal mid = new BigDecimal(0);
        mid = target.subtract(Max);
        if(mid.doubleValue()>0)
            target = Max;
        mid = target.subtract(Min);
        if(mid.doubleValue()<0)
            target = Min;
        int result = target.intValue();
        return result;
    }
}
