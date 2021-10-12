class Solution {
public:
    int countProfit(vector<int>&nums,int currentPosition,int end)
    {
        int consider=0;
        int notConsider=0;
        if(currentPosition>=end)
        {
            return 0;
        }
        else
        {
            consider= nums[currentPosition]+countProfit(nums,currentPosition+2,end);
            notConsider=nums[currentPosition]+countProfit(nums,currentPosition+3,end);
        }
        return max(consider,notConsider);
    }
    int rob(vector<int>& nums) {
        int end=nums.size();
        int a=countProfit(nums,0,end);
        int b=countProfit(nums,1,end);
        return max(a,b);
    }
};