class Solution {
public:
    int bottomUpNSquared(vector<int>& nums){
        vector<int> answer(nums.size(), 1);
        answer[0] = 1;
        for(int i = 1;i < nums.size();++i){
            for(int j = i-1;j >= 0;--j){
                if(nums[j] < nums[i]){
                    answer[i] = max(answer[i], answer[j] + 1);
                }
            }
        }
        return *max_element(answer.begin(), answer.end());
    }
    unordered_map<int, int> cache;
    int topDown(int index, vector<int>& nums){
        if(index == nums.size())
            return 0;
        if(cache.find(index) != cache.end())
            return cache[index];
        int answer = 1;
        topDown(index + 1, nums);
        for(int i = index + 1;i < nums.size();++i){
            if(nums[i] > nums[index]){
                answer = max(answer, topDown(i, nums) + 1);
            }
        }
        return cache[index] = answer;
    }
    int bottomUpNLogN(vector<int>& nums){
        int answer = 1;
        vector<int> longest;
        vector<int>::iterator it;
        for(int i=0; i < nums.size(); i++){
            it = lower_bound(longest.begin(), longest.end(), nums[i]);
            if(it == longest.end())
                longest.push_back(nums[i]);
            else
                *it = nums[i];
        }
        return longest.size();
    }
    int lengthOfLIS(vector<int>& nums) {
        // BOTTOM-UP OPTIMIZED
        return bottomUpNLogN(nums);
        // TOP-DOWN
        // cache.clear();
        // topDown(0, nums);
        // int answer = 1;
        // for(auto it: cache){
        //     answer = max(answer, it.second);
        // }
        // return answer;
        // BOTTOM-UP
        // return bottomUpNSquared(nums);
    }
};