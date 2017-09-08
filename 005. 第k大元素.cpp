class Solution 
{
public:
    int kthLargestElement(int k, vector<int> nums) 
    {
        k=nums.size()+1-k;
        return diGui(k,nums,0,nums.size()-1);
    }
    int diGui(int k,vector<int>& nums,int zuo,int you)
    {
        int index = select(nums,zuo,you);
        if(index==k-1)
            return nums[index];
        if(index<k-1)
            return diGui(k,nums,index+1,you);
        else
            return diGui(k,nums,zuo,index-1);
    }
    int select(vector<int>& nums,int zuo,int you)
    {
        if(zuo==you)
            return zuo;
        int biao_zhun=nums[you];
        int index=zuo-1;
        for(int i=zuo;i<you;++i)
        {
            if(nums[i]<biao_zhun)
            {
                int temp;
                temp = nums[i];
                nums[i]=nums[++index];
                nums[index]=temp;
            }
        }
        nums[you]=nums[++index];
        nums[index]=biao_zhun;
        return index;
    }
};
