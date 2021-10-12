class Solution {
public:
       long minCoin(vector<int>& coins,int currIndex,int amount,unordered_map<string,long>& mp)
    {
        if(amount==0)
        {
            return 1;
        }
        
        if(currIndex>=coins.size())
        {
            return 0;
        }
        
        string currKey=to_string(currIndex)+";"+to_string(amount);
        
//         if(mp.find(currKey)!=mp.end())
//         {
//             return mp[currKey];
//         }
        
        long consider=0;
        long notConsider;
        
        if(coins[currIndex]<=amount)
        {
            consider=minCoin(coins,currIndex,amount-coins[currIndex],mp);
        }
        
        notConsider=minCoin(coins,currIndex+1,amount,mp);
        // mp[currKey]=consider+notConsider;
        // return mp[currKey];
           return consider+notConsider;
    }
    int change(int amount, vector<int>& coins) {
         unordered_map<string,long> mp;
        
        if(minCoin(coins,0,amount,mp)==0)
        {
            return 0;
        }
        
        return minCoin(coins,0,amount,mp);
    }
};