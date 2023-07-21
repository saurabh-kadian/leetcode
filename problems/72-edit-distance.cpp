class Solution {
public:
    unordered_map<string, int> cache;
    int solve(int i, int j, string& first, string& second){
        // all insert
        if(i == first.size())
            return second.size() - j;
        // all delete
        if(j == second.size())
            return first.size() - i;
        
        stringstream ss;
        ss << i << "-" << j;
        string key = ss.str();
        if(cache.find(key) != cache.end())
            return cache[key];

        int answer = 1e4;
        // if match?
        if(first[i] == second[j]){
            answer = min(answer, solve(i+1, j+1, first, second));
        }
        else {
        // insert
        answer = min(answer, solve(i, j + 1, first, second) + 1);
        // delete
        answer = min(answer, solve(i + 1, j, first, second) + 1);
        // replace
        answer = min(answer, solve(i + 1, j + 1, first, second) + 1);
        }
        return cache[key] = answer;
    }
    int bottomUp(string first, string second){
        vector<vector<int> > dp(first.size() + 2, vector<int>(second.size() + 2, 1e4));
        for(int i = first.size();i >= 0;--i){
            for(int j = second.size();j >= 0;--j){
                if(i == first.size()){                          // all insert now
                    dp[i][j] = second.size() - j;
                    continue;
                }
                if(j == second.size()){                         // all delete now
                    dp[i][j] = first.size() - i;
                    continue;
                }
                if(first[i] == second[j]){                      // same no action required
                    dp[i][j] = min(dp[i][j], 
                                   dp[i+1][j+1]);
                } else {
                    dp[i][j] = min(
                                    dp[i][j],
                                    min(
                                        dp[i][j+1] + 1,         // insert
                                        min(
                                            dp[i+1][j] + 1,     // delete
                                            dp[i+1][j+1] + 1    // replace
                                        )
                                    )
                                );
                }
            }
        }
        return dp[0][0];
    }
    int minDistance(string word1, string word2) {
        return bottomUp(word1, word2);
        // return solve(0, 0, word1, word2);
    }
};