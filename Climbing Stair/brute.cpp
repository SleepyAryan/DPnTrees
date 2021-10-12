class Solution {
public:
    int countStairs(int n,int currentStair)
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
            oneStep=countStairs(n,currentStair+1);
            twoStep=countStairs(n,currentStair+2);
        }
        return oneStep+twoStep;
    }
    int climbStairs(int n) {
       return countStairs(n,0); 
    }
};