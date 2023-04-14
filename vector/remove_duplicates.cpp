//
// Created by 姚轩 on 2023/3/10.
//
#include "common.h"

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if (nums.size() == 1){
            return 1;
        }
        int anchorNum = nums[0];
        int insertPointer = 1;
        int curPointer = 1;
        while (curPointer < nums.size()){
            if (nums[curPointer] != anchorNum){
                anchorNum = nums[curPointer];
                nums[insertPointer] = anchorNum;
                curPointer++;
                insertPointer++;
            }else{
                curPointer++;
            }
        }
        return insertPointer++;
    }
};

int main() {
    //vector<int> nums {1,2,7,7};
    vector<int> nums {1,1,2,7};
    vector<int> expectedNums {1,2,7};
    Solution sol = Solution();
    int length = sol.removeDuplicates(nums);
    assert (length == expectedNums.size());
    for (int i = 0; i < length; i++) {
        assert (nums[i] == expectedNums[i]);
    }
}