class Solution {
public:
    int countStairs(int n,int currentStair,unordered_map<int,int>&mp)
    {
        int oneStep=0;
        int twoStep=0;
        if(currentStair == n)
        {
            return 1;
        }
        if(currentStair>n)
        {
            return 0;
        }
        else
        {
            if(mp.find(currentStair)!=mp.end())
            {
                return mp[currentStair];
            }
            oneStep=countStairs(n,currentStair+1,mp);
            twoStep=countStairs(n,currentStair+2,mp);
        }
        mp[currentStair]=oneStep+twoStep;
        return oneStep+twoStep;
    }
    int climbStairs(int n) {
        unordered_map<int,int> mp;
       return countStairs(n,0,mp); 
    }
};