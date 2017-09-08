class Solution 
{
public:
    void sortLetters(string &letters) 
    {
        int n=letters.length();
        if(n<=1)
            return;
        int zuo_index=0;
        int you_index=n-1;
        while(zuo_index<you_index)
        {
            while(zuo_index<n&&letters[zuo_index]>='a'&&letters[zuo_index]<='z')
            {
                ++zuo_index;
            }
            while(you_index>=0&&letters[you_index]>='A'&&letters[you_index]<='Z')
            {
                --you_index;
            }
            if(zuo_index<you_index)
                swap(letters[zuo_index],letters[you_index]);
        }
    }
};
