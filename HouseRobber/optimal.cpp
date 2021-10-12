class Solution {
public:
    int countProfit(vector<int>&nums,int currentPosition,int end,unordered_map<int,int>& mp)
    {
        int consider=0;
        int notConsider=0;
        if(currentPosition>=end)
        {
            return 0;
        }
        else
        {
            if(mp.find(currentPosition)!=mp.end())
            {
                return mp[currentPosition];
            }
            consider= nums[currentPosition]+countProfit(nums,currentPosition+2,end,mp);
            notConsider=nums[currentPosition]+countProfit(nums,currentPosition+3,end,mp);
        }
        mp[currentPosition]=max(consider,notConsider);
        return max(consider,notConsider);
    }
    int rob(vector<int>& nums) {
        int end=nums.size();
        unordered_map<int,int>mp;
        int a=countProfit(nums,0,end,mp);
        int b=countProfit(nums,1,end,mp);
        return max(a,b);
    }
};