class Solution {
public:
    int maximum69Number (int num) {
        
        deque<int> digits;
        
        while (num) {
            digits.push_front(num % 10);
            num /= 10;
        }
                
        for (int i = 0; i < digits.size(); i++) {
            if (digits[i] == 6) {
                digits[i] = 9;
                break;
            }
        }
        
        long long res = 0;
        long long pow = 1;
        
        while (digits.size()) {
            res += pow * digits.back();
            digits.pop_back();
            pow *= 10;
        }
        
        return res;
    }
};