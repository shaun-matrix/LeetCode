#include "common.h"

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if (s.length() == 0){
            return 0;
        }
        if (s.length() == 1){
            return 1;
        }
        unordered_map<char, size_t> substring_map;
        unordered_map<char, size_t>::iterator got_iter;
        size_t start = 0;
        size_t longest_size = 0;
        size_t cur_win_size = 1;
        substring_map.insert({s[start], 1});
        for (size_t i = 1; i < s.length(); i++) {
            got_iter = substring_map.find(s[i]);
            if (got_iter == substring_map.end()) {
                cur_win_size += 1;
                longest_size = (longest_size>cur_win_size) ? longest_size: cur_win_size;
                substring_map.insert({s[i], 1});
            }else{
                char repeated_char = got_iter->first;
                while (start < i){
                    if(s[start] == repeated_char){
                        start++;
                        cur_win_size = i - start + 1;
                        longest_size = (longest_size>cur_win_size) ? longest_size: cur_win_size;
                        break;
                    }
                    else {
                        substring_map.erase(s[start]);
                        start++;
                    }
                }
            }
        }
        return longest_size;
    }
};

int main() {
    //string s = "abcabcbb";
    string s = "pwwkewc";
    //string s = "bbbbb";
    Solution sol = Solution();
    int longest_size = sol.lengthOfLongestSubstring(s);
    cout << "length of longest substring: " << longest_size << endl;
}
