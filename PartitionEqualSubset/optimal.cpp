class Solution {
public:
    bool isTrue(vector<int>& nums,int target,int current,unordered_map<string,bool>& mp)
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
        string CurrentKey = to_string(target) + ";" + to_string(current);
        if(mp.find(CurrentKey)!=mp.end())
        {
            return mp[CurrentKey];
        }
            if(nums[current]<=target)
            {
                considered=isTrue(nums,target-nums[current],current+1,mp);
            }
            int NotConsidered=isTrue(nums,target,current+1,mp);
        mp[CurrentKey]=considered || NotConsidered;
        return mp[CurrentKey];
    }
    bool canPartition(vector<int>& nums) {
        int n=nums.size();
        int sum=0;
        unordered_map<string,bool> mp;
        for(auto num:nums)
        {
            sum+=num;
        }
        if(sum%2==1)return false;
        int target=sum/2;
        return isTrue(nums,target,0,mp);
    }
};