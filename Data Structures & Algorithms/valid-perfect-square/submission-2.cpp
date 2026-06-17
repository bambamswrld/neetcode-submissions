class Solution {
public:
    bool isPerfectSquare(int num) {
        long long begin = 1;
        long long end = num;
        while(begin <= end) {
            long long mid = begin + (end - begin) / 2;
            long long sqr = mid * mid;
            if(sqr < num) {
                begin = mid + 1;
            }
            else if(sqr > num) {
                end = mid - 1;
            }
            else {
                return true;
            }
        }
        return false;
    }
};