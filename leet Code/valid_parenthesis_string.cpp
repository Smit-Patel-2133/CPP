#include <iostream>
#include <string>

class Solution {
public:
    bool checkValidString(std::string s) {
        int leftCount = 0;
        int starCount = 0;
        
        // Scan from left to right
        for (char c : s) {
            if (c == '(') {
                leftCount++;
            } else if (c == '*') {
                starCount++;
            } else { // c == ')'
                if (leftCount > 0) {
                    leftCount--;
                } else if (starCount > 0) {
                    starCount--;
                } else {
                    return false; // ')' without matching '(' or '*'
                }
            }
        }
        
        // After scanning from left to right, check if remaining '*' can balance '('
        if (leftCount > starCount) {
            return false;
        }
        
        // Reset counters
        leftCount = 0;
        starCount = 0;
        
        // Scan from right to left
        for (int i = s.size() - 1; i >= 0; i--) {
            char c = s[i];
            if (c == ')') {
                leftCount++;
            } else if (c == '*') {
                starCount++;
            } else { // c == '('
                if (leftCount > 0) {
                    leftCount--;
                } else if (starCount > 0) {
                    starCount--;
                } else {
                    return false; // '(' without matching ')' or '*'
                }
            }
        }
        
        return true;
    }
};

int main() {
    Solution solution;
    
    // Example usage
    std::string input1 = "()";
    std::cout << "Input: " << input1 << ", Output: " << (solution.checkValidString(input1) ? "true" : "false") << std::endl;
    
    std::string input2 = "(*)";
    std::cout << "Input: " << input2 << ", Output: " << (solution.checkValidString(input2) ? "true" : "false") << std::endl;
    
    std::string input3 = "(*))";
    std::cout << "Input: " << input3 << ", Output: " << (solution.checkValidString(input3) ? "true" : "false") << std::endl;
    
    return 0;
}
