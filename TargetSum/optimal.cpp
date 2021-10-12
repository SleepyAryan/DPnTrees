class Solution {
public:
    int CheckSum(vector<int>& nums,int target,int current,unordered_map<string,int>& mp)
    {
        if(target==0 && current>=nums.size())
        {
            return 1;
        }
        if(current>=nums.size() && target!=0)
        {
            return 0;
        }
        string currentKey=to_string(target)+";"+to_string(current);
        if(mp.find(currentKey)!=mp.end())
        {
            return mp[currentKey];
        }
       int positive=CheckSum(nums,target-nums[current],current+1,mp);
       int negative=CheckSum(nums,target+nums[current],current+1,mp); 
        mp[currentKey] = positive+negative;
        return positive+negative;
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        unordered_map<string,int>mp;
        return CheckSum(nums,target,0,mp);
    }
};