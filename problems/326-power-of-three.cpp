class Solution {
public:
    bool shorter(int n){
        // 3^19 last power to fit int
        return (n > 0 && 1162261467%n == 0);
    }
    bool isPowerOfThree(int n) {
        return shorter(n);

        if(n <= 0)
            return false;
        while(n%3 == 0)
            n/=3;
        return (n == 1 ? true : false);
    }
};