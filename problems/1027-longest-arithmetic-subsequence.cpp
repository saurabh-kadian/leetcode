class Solution {
public:
    int longestArithSeqLength(vector<int>& nums) {
        int answer = 1;
        for(int seq = -502;seq <= 502;++seq){
            // unordered_map -> gives TLE here
            vector<int> cache(2000, 0);
            cache[nums[0]] = 1;
            int maxKey = 1;
            for(int i = 1;i < nums.size();++i){
                if(nums[i]-seq >= 0 && cache[nums[i]-seq] > 0)
                    cache[nums[i]] = cache[nums[i]-seq] + 1;
                else
                    cache[nums[i]] = 1;
                maxKey = max(maxKey, cache[nums[i]]);
            }
            answer = max(maxKey, answer);
        }
        return answer;
    }
};