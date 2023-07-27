class Solution {
public:
    unordered_map<string, int> cache;
    int solve(int i, int j, string& t, string& p){
        if(i == t.size() || j == p.size())
            return 0;

        stringstream ss;
        ss << i << "-" << j << endl;
        string key = ss.str();

        if(cache.count(key))
            return cache[key];

        if(t[i] == p[j])
            return cache[key] = solve(i + 1, j + 1, t, p) + 1;
        
        return cache[key] = max(solve(i + 1, j, t, p), solve(i, j + 1, t, p));
    }
    int bottomUp(string t, string p){
        vector<vector<int> > dp(t.size() + 4, vector<int>(p.size() + 4, 0));
        for(int i = t.size() - 1;i >= 0;--i){
            for(int j = p.size() - 1;j >= 0;--j){
                if(t[i] == p[j])
                    dp[i][j] = dp[i+1][j+1] + 1;
                else
                    dp[i][j] = max(dp[i+1][j], dp[i][j+1]);
            }
        }
        return dp[0][0];
    }
    int longestCommonSubsequence(string text1, string text2) {
        return bottomUp(text1, text2);
        // return solve(0, 0, text1, text2);
    }
};