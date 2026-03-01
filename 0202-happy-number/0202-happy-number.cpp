class Solution {
public:
    int getnum(int n) {
        int val = 0;
        while(n>0) {
            int digit = n % 10;
            val += digit * digit;
            n /= 10;
        }
        return val;
    }

    bool isHappy(int n) {
        int slow = n, fast = n;

        while(fast != 1) {
            slow = getnum(slow);
            fast = getnum(fast);
            fast = getnum(fast);

            if(slow == fast && slow != 1) {
              return false;
            }
        }
        return true;
    }
};
