class Solution {
public:
    int countCoin(vector<int>& coins,int amount,int current)
    {
        if(amount==0)
        {
            return 0;
        }
        if(current>=coins.size() && amount!=0)
        {
            return 10000;
        }
        int consider=10000;
        if(coins[current]<=amount)
        {
        consider=1+countCoin(coins,amount-coins[current],current);
        }
        int notConsider=countCoin(coins,amount,current+1);
        return min(consider,notConsider);
    }
    int coinChange(vector<int>& coins, int amount) {
        if(countCoin(coins,amount,0)==10000)
        {
            return -1;
        }
        return countCoin(coins,amount,0);
    }
};