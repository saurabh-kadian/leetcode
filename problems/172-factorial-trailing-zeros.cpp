class Solution {
public:
    int trailingZeroes(int n) {
        int pow5 = 5;
        int sum = 0;
        while(pow5 <= n){
            sum += n/pow5;
            pow5 *= 5;
        }
        return sum;
    }
};