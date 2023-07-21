class Solution {
public:
    unordered_map<int, int> cache;
    int solve(int index, vector<int>& frequency){
        if(index >= frequency.size())
            return 0;
        
        if(cache.find(index) != cache.end())
            return cache[index];
        
        return cache[index] = max(solve(index + 1, frequency),              // no take 
                   solve(index + 2, frequency) + frequency[index]*index);   // take
    }
    int bottomUp(vector<int>& frequency){
        vector<int> answer(frequency.size() + 4, 0);
        for(int i = frequency.size()-1;i >= 0;--i)
            answer[i] = max(answer[i+1],                                    // no take 
                            answer[i+2] + frequency[i]*i);                  // take
        return answer[0];
    }
    int deleteAndEarn(vector<int>& nums) {
        // cache.clear();
        vector<int> frequency((int)1e4+5, 0);
        for(int i = 0;i < nums.size();++i)
            frequency[nums[i]]++;
        // return solve(0, frequency);
        return bottomUp(frequency);
    }
};