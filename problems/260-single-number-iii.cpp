class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        long combinedXor = 0;
        for(int i = 0;i < nums.size();++i)
            combinedXor ^= nums[i];
        
        // lsb which is set, also used in fenwick tree
        // lsb = the least significat non-zero bit of number
        // a & (-a) {}{}{}{}{}{} a ^ (a & (a-1))
        // long lsb = (combinedXor^(combinedXor&(combinedXor-1)));
        long lsb = combinedXor & (-combinedXor);
        int whichGiveOne = 0;
        int whichGiveZero = 0;
        for(int i = 0;i < nums.size();++i){
            if(nums[i] & lsb)
                whichGiveOne ^= nums[i];
            else
                whichGiveZero ^= nums[i];
        }
        vector<int> x(2);
        x[0] = whichGiveOne;
        x[1] = whichGiveZero;
        return x;
    }
};