class Solution {
public:
    int alternatingSubarray(vector<int>& nums) {
        int start = 0;
        int answer = 0;
        for(int i = 1;i < nums.size();++i){
            int shouldBe = ((i - start)%2 ? nums[start] + 1 : nums[start]);
            if(nums[i] != shouldBe){
                // [2,3,4,] => i is at 4. [3,4] can start a new sequence
                if(nums[i-1] + 1 == nums[i]){
                    start = i-1;
                    continue;
                }
                start = i;
                continue;
            }
            answer = max(answer, i - start + 1);
        }
        return (answer == 0 ? -1 : answer);
    }
};