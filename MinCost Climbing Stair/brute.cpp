class Solution {
public:
    int countMoney(vector<int>& cost,int currentStair,int target)
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
            oneStep=cost[currentStair] + countMoney(cost,currentStair+1,target);
            twoStep=cost[currentStair] + countMoney(cost,currentStair+2,target);
        }
        return min(oneStep,twoStep);
    }
    int minCostClimbingStairs(vector<int>& cost) {
        int target=cost.size(); 
        int a=countMoney(cost,0,target);
        int b=countMoney(cost,1,target);
        return min(a,b);
    }
};