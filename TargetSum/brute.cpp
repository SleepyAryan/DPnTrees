class Solution {
public:
    int CheckSum(vector<int>& nums,int target,int current)
    {
        if(target==0 && current>=nums.size())
        {
            return 1;
        }
        if(current>=nums.size() && target!=0)
        {
            return 0;
        }
       int positive=CheckSum(nums,target-nums[current],current+1);
       int negative=CheckSum(nums,target+nums[current],current+1); 
        return positive+negative;
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        return CheckSum(nums,target,0);
    }
};