class Solution {
public:
    int check(string text1,string text2,int i,int j,unordered_map<string,int>& mp)
    {
        if(i>=text1.size() || j>=text2.size())
        {
            return 0;
        }
        string currentKey= to_string(i)+";"+to_string(j);
        if(mp.find(currentKey)!=mp.end())
        {
            return mp[currentKey];
        }
        if(text1[i]==text2[j])
        {
      return 1+check(text1,text2,i+1,j+1,mp);
        }
        int a=check(text1,text2,i+1,j,mp);
        int b=check(text1,text2,i,j+1,mp);
        mp[currentKey]=max(a,b);
        return mp[currentKey];        
    }
    int longestPalindromeSubseq(string s) {
        unordered_map<string,int>mp;
        string text1=s;
        string text2=s;
      reverse(text2.begin(),text2.end());
        return check(text1,text2,0,0,mp);
    }
};