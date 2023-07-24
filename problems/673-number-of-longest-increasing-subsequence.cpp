// https://leetcode.com/problems/number-of-longest-increasing-subsequence/solutions/1643753/python-o-nlogn-solution-w-detailed-explanation-of-how-to-develop-a-binary-search-solution-from-300/
// --> O(n^2) can be optimized to O(nlgn)

// [1, 3, 2, 5, 4, 7] reduced to list where index is the length of LIS [[1], [3, 2], [5, 4], [7]]
// Then we go ahead and also count how many ways to get this, [[(1, 1)], [(3, 1), (2, 1)], [(5, 2), (4, 2)], [(7, 4)]]
// Now how do reduce the looping of elements on each size? starting keeping prefix sums
// [[(1, 1)], [(2, 1), (3, 2)], [(4, 2), (5, 4)], [(7, 4)]]

class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        vector<int> answers(nums.size(), 1);
        vector<int> countOfAnswers(nums.size(), 0);
        countOfAnswers[0] = 1;
        int answer = 1;
        int maxi = 1;
        for(int i = 1;i < answers.size();++i){
            unordered_map<int, int> cache;
            cache[1] = 1;
            for(int j = i-1;j >= 0;--j){
                if(nums[i] > nums[j]){
                    if(answers[j] + 1 >= answers[i])
                        cache[answers[j] + 1] += countOfAnswers[j];
                    answers[i] = max(answers[i], answers[j] + 1);
                }
            }
            countOfAnswers[i] = cache[answers[i]];
            maxi = max(maxi, answers[i]);
        }
        int finalAnswer = 0;
        for(int i = 0;i < countOfAnswers.size();++i){
            if(answers[i] == maxi){
                finalAnswer += countOfAnswers[i];
            }
        }
        return finalAnswer;
    }
};