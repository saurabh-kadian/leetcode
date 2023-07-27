class Solution {
public:
    unordered_map<string, int> cache;
    int solve(int i, int j, string& s){
        if(i >= j)
            return 0;
        
        stringstream ss;
        ss << i << "-" << j;
        string key = ss.str();

        if(cache.count(key))
            return cache[key];
        
        if(s[i] == s[j])
            return cache[key] = solve(i+1, j-1, s);
        
        return cache[key] = min(solve(i + 1, j, s), solve(i, j - 1, s)) + 1;
    }
    int bottomUp(string& s){
        vector<vector<int> > dp(s.size() + 2, vector<int>(s.size() + 2, 0));
        for(int i = s.size() - 1;i >= 0;--i){
            for(int j = 0;j <= s.size() - 1;++j){
                if(i >= j)
                    continue;
                if(s[i] == s[j])
                    dp[i][j] = dp[i+1][j-1];
                else
                    dp[i][j] = min(dp[i+1][j], dp[i][j-1]) + 1;
            }
        }
        return dp[0][s.size()-1];
    }
    int minInsertions(string s) {
        return bottomUp(s);
        // cache.clear();
        // return solve(0, s.size() - 1, s);
    }
};
