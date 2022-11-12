class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        
        int carry = 1;
        int n = digits.size();
        
        for (int i = n - 1; i >= 0; i--) {
            int sum = digits[i] + carry;
            carry = sum / 10;
            digits[i] = sum % 10;
            if (sum < 10) break;
        }
        
        if (digits.front() == 0) {
            digits.insert(digits.begin(), 1);   
        }
        
        return digits;
    }
};