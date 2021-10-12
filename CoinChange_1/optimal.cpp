class Solution {
public:
    int countCoin(vector<int>& coins,int amount,int current,unordered_map<string,int>& mp)
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
        string currentKey=to_string(amount)+";"+to_string(current);
        if(mp.find(currentKey)!=mp.end())
        {
            return mp[currentKey];
        }
        if(coins[current]<=amount)
        {
        consider=1+countCoin(coins,amount-coins[current],current,mp);
        }
        int notConsider=countCoin(coins,amount,current+1,mp);
        mp[currentKey]=min(consider,notConsider);
        return min(consider,notConsider);
    }
    int coinChange(vector<int>& coins, int amount) {
        unordered_map<string,int>mp;
        if(countCoin(coins,amount,0,mp)==10000)
        {
            return -1;
        }
        return countCoin(coins,amount,0,mp);
    }
};