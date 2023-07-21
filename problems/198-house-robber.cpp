class Solution {
public:
    unordered_map<int, int> cache;
    int solve(int index, vector<int>& nums){
        if(index >= nums.size())
            return 0;

        if(cache.find(index) != cache.end())
            return cache[index];
        
        return max(solve(index + 2, nums) + nums[index],    // rob 
                   solve(index + 1, nums));                 // not rob
    }
    int bottomUp(vector<int>& nums){
        vector<int> answer(nums.size() + 4, 0);
        for(int i = nums.size()-1;i >= 0;--i){
            answer[i] = max(answer[i+2] + nums[i], answer[i+1]);
        }
        return answer[0];
    }
    int rob(vector<int>& nums) {
        return bottomUp(nums);
        // cache.clear();
        // return solve(0, nums);
    }
};