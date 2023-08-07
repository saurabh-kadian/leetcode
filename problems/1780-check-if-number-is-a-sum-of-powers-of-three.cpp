class Solution {
public:
    bool checkPowersOfThree(int n) {
        while(n != 0){
            if(n % 3 == 2)
                return false;
            if(n % 3 == 1)
                n--;
            n /= 3;
        }
        return true;
    }
};