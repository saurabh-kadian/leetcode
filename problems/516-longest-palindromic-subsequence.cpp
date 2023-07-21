class Solution {
public:
    unordered_map<string, int> cache;
    int solve(int i, int j, string& s){
        if(j == i + 1)
            return (s[i]==s[j]) + 1;
        if(i == j)
            return 1;

        stringstream ss;
        ss << i << "-" << j;
        string key = ss.str();
        if(cache.find(key) != cache.end())
            return cache[key];

        if(s[i] == s[j])
            return cache[key]=solve(i+1, j-1, s) + 2;
        return cache[key]=max(solve(i+1, j, s), solve(i, j-1, s));
    }
    int bottomUp(string s){
        vector<vector<int> > dp(s.size() + 2, vector<int>(s.size() + 2, 0));
        for(int i = s.size()-1;i >= 0;--i){
            for(int j = 0;j < s.size();++j){
                if(i > j)
                    continue;
                if(i == j)
                    dp[i][j] = 1;
                else if(i + 1 == j)
                    dp[i][j] = (s[i]==s[j]) + 1;
                else if(s[i] == s[j])
                    dp[i][j] = dp[i+1][j-1] + 2;
                else
                    dp[i][j] = max(dp[i+1][j], dp[i][j-1]);
            }
        }
        return dp[0][s.size()-1];
    }
    int longestPalindromeSubseq(string s) {
        return bottomUp(s);
        // return solve(0, s.size()-1, s);
    }
};