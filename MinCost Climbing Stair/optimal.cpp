class Solution {
public:
    int countMoney(vector<int>& cost,int currentStair,int target,unordered_map<int,int>& mp)
    {
        int oneStep=0;
        int twoStep=0;
        if(currentStair==target)
        {
            return 0;
        }
        if(currentStair>target)
        {
            return 100000;
        }
        else
        {
            if(mp.find(currentStair)!=mp.end())
            {
                return mp[currentStair];
            }
            oneStep=cost[currentStair] + countMoney(cost,currentStair+1,target,mp);
            twoStep=cost[currentStair] + countMoney(cost,currentStair+2,target,mp);
        }
        mp[currentStair]=min(oneStep,twoStep);
        return min(oneStep,twoStep);
    }
    int minCostClimbingStairs(vector<int>& cost) {
        int target=cost.size(); 
        unordered_map<int,int>mp;
        int a=countMoney(cost,0,target,mp);
        int b=countMoney(cost,1,target,mp);
        return min(a,b);
    }
};