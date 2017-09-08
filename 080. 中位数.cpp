class Solution 
{
public:
    int median(vector<int> &nums) 
    {
        int len=nums.size();
        int mu_biao_index = (len-1)/2;
        return findK(nums,0,len-1,mu_biao_index);
    }
    int findK(vector<int> &nums,int zuo,int you,int k)
    {
        int mid=select(nums,zuo,you);
        if(k==mid)
            return nums[k];
        else if(k<mid)
            return findK(nums,zuo,mid-1,k);
        else
            return findK(nums,mid+1,you,k);
    }
    int select(vector<int> &nums,int zuo,int you)
    {
        if(zuo==you)
            return zuo;
        int index = zuo;
        int biao_zhun = nums[you];
        for(int i=zuo;i<you;++i)
        {
            if(nums[i]<biao_zhun)
            {
                swap(nums[index],nums[i]);
                ++index;
            }
        }
        swap(nums[you],nums[index]);
        return index;
    }
};
