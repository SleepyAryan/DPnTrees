class Solution {
public:
    bool isTrue(vector<int>& nums,int target,int current)
    {
        if(target==0)
        {
            return true;
        }
        if(current>=nums.size() && target!=0 )
        {
            return false;
        }
        bool considered=false;
            if(nums[current]<=target)
            {
                considered=isTrue(nums,target-nums[current],current+1);
            }
            int NotConsidered=isTrue(nums,target,current+1);
        return considered || NotConsidered;
    }
    bool canPartition(vector<int>& nums) {
        int n=nums.size();
        int sum=0;
        for(auto num:nums)
        {
            sum+=num;
        }
        if(sum%2==1)return false;
        int target=sum/2;
        return isTrue(nums,target,0);
    }
};