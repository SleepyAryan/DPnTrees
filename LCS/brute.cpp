class Solution {
public:
    int check(string text1,string text2,int i,int j)
    {
        if(i>=text1.size() || j>=text2.size())
        {
            return 0;
        }
        if(text1[i]==text2[j])
        {
      return 1+check(text1,text2,i+1,j+1);
        }
        int a=check(text1,text2,i+1,j);
        int b=check(text1,text2,i,j+1);
        return max(a,b);        
    }
    int longestCommonSubsequence(string text1, string text2) {
        return check(text1,text2,0,0);
    }
};