#include "common.h"

class Solution {
public:
    int romanToInt(string s) {

        unordered_map<char, size_t> roman_to_int_map = {{'I', 1}, {'V', 5}, {'X', 10},\
          {'L', 50}, {'C', 100}, {'D', 500}, {'M', 1000}};
        size_t num_int = roman_to_int_map[s[0]];
        size_t prev_int = num_int;
        for(size_t i=1; i<s.length(); i++){
            if (roman_to_int_map[s[i]] > prev_int){
                num_int += roman_to_int_map[s[i]] - 2 * prev_int;
                prev_int = 10000;
            }else{
                num_int += roman_to_int_map[s[i]];
                prev_int = roman_to_int_map[s[i]];
            }
        }
        return num_int;
    }
};

int main() {
    string s = "III";
    s = "IV";
    s = "IX";
    s = "LVIII";
    s = "MCMXCIV";
    Solution sol = Solution();
    int num_int = sol.romanToInt(s);
    cout << "roman to int: " << num_int << endl;
}
