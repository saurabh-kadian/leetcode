class Solution {
public:
    unordered_map<string, int> cache;
    int solve(int index, int change, vector<int>& coins){   // TLE
        if(index == coins.size())
            return (change == 0 ? 0 : 1e8);
        if(change < 0)
            return 1e8;

        stringstream ss;
        ss << index << "-" << change;
        string key = ss.str();

        if(cache.count(key))
            return cache[key];
        
        int answer = 1e8;
        for(int i = 0;change >= i*coins[index];i++){
            answer = min(answer, solve(index + 1, change - i*coins[index], coins) + i);
        }
        return cache[key] = answer;
    }
    int bottomUp(vector<int>& coins, int& amount){  // TLE
        vector<vector<int> > dp(coins.size() + 4, vector<int>(amount + 4, 1e6));
        for(int i = coins.size();i >= 0;--i){
            for(int j = 0;j <= amount;++j){
                if(i == coins.size()){
                    if(j == 0)
                        dp[i][j] = 0;
                    continue;
                }
                for(int k = 0;k*coins[i] <= j;++k){
                    dp[i][j] = min(dp[i][j], dp[i + 1][j - k*coins[i]] + k);
                }
            }
        }
        return dp[0][amount];
    }
    int otherWayAround(vector<int>& coins, int& amount){    // TLE
        vector<vector<int> > dp(coins.size() + 2, vector<int>(amount + 2, 1e6));
        for(int i = 0;i < coins.size();++i){
            for(int j = 0;j <= amount;++j){
                if(j == 0){
                    dp[i][j] = 0;
                    continue;
                }
                for(int k = 0;k * coins[i] <= j;++k){
                    if(i == 0){
                        dp[i][j] = (k*coins[i] == j ? k : 1e6);
                        continue;
                    }
                    dp[i][j] = min(dp[i][j], dp[i-1][j - k*coins[i]] + k);
                }
            }
        }
        return dp[coins.size() - 1][amount];
    }
    int otherWayAroundSpaceOptimized(vector<int>& coins, int& amount){  // TLE
        vector<int> dp(amount + 2, 1e6);
        for(int i = 0;i < coins.size();++i){
            vector<int> temp(amount + 2, 1e6);
            for(int j = 0;j <= amount;++j){
                if(j == 0){
                    temp[j] = 0;
                    continue;
                }
                for(int k = 0;k * coins[i] <= j;++k){
                    if(i == 0){
                        temp[j] = (k*coins[i] == j ? k : 1e6);
                        continue;
                    }
                    temp[j] = min(temp[j], dp[j - k*coins[i]] + k);
                }
            }
            dp = temp;
        }
        return dp[amount];
    }
    int otherWayAroundWithArray(vector<int>& coins, int amount){    // TLE
        int dp[14][10004];
        memset(&dp[0][0], 1e6, sizeof(dp));
        for(int i = 0;i < coins.size();++i){
            for(int j = 0;j <= amount;++j){
                if(j == 0){
                    dp[i][j] = 0;
                    continue;
                }
                for(int k = 0;k * coins[i] <= j;++k){
                    if(i == 0){
                        dp[i][j] = (k*coins[i] == j ? k : 1e6);
                        continue;
                    }
                    dp[i][j] = min(dp[i][j], dp[i-1][j - k*coins[i]] + k);
                }
            }
        }
        return dp[coins.size() - 1][amount];
    }
    int revertItAround(vector<int>& coins, int amount){     // AC
        int dp[10004];
        memset(&dp[0], 1e6, sizeof(dp));
        dp[0] = 0;
        for(int i = 1;i <= amount + 1;++i){
            for(int j = 0;j < coins.size();++j){
                if(i - coins[j] < 0)
                    break;
                dp[i] = min(dp[i], dp[i-coins[j]] + 1);
            }
        }
        return dp[amount];
    }
    int otherWayAroundWithNoThirdLoop(vector<int>& coins, int amount){
        // int dp[14][10004];
        // memset(&dp[0][0], 1e6, sizeof(dp));
        vector<vector<int> > dp(coins.size() + 4, vector<int>(amount + 4, 1e6));
        for(int i = coins.size();i >= 0;--i){
            for(int j = 0;j <= amount;++j){
                if(i == coins.size()){
                    if(j == 0)
                        dp[i][j] = 0;
                    continue;
                }
                if(j < coins[i]){
                    dp[i][j] = dp[i + 1][j];
                    continue;
                }
                dp[i][j] = min(dp[i+1][j], dp[i][j - coins[i]] + 1);
            }
        }
        return dp[0][amount];    
    }
    int topDownRemoveK(int index, int change, vector<int>& coins){   // TLE
        if(index == coins.size())
            return (change == 0 ? 0 : 1e8);
        if(change < 0)
            return 1e8;

        stringstream ss;
        ss << index << "-" << change;
        string key = ss.str();

        if(cache.count(key))
            return cache[key];
        
        int answer = min(solve(index + 1, change, coins), 
                         solve(index, change - coins[index], coins) + 1);
        return cache[key] = answer;
    }
    int coinChange(vector<int>& coins, int amount) {
        sort(coins.begin(), coins.end());
        // int answer = topDownRemoveK(0, amount, coins); // TLE
        int answer = otherWayAroundWithNoThirdLoop(coins, amount); // AC with array 84%, with vector 7%
        // int answer = revertItAround(coins, amount); // AC
        // int answer = otherWayAroundWithArray(coins, amount); // TLE
        // int answer = otherWayAroundSpaceOptimized(coins, amount); // TLE
        // int answer = otherWayAround(coins, amount); // TLE 
        // int answer = bottomUp(coins, amount); // TLE
        // int answer = solve(0, amount, coins); // TLE
        return (answer >= 1e6 ? -1 : answer);
    }
};

