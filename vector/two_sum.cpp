#include "common.h"

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> indexes;
        for (size_t i=0; i < nums.size()-1; i++){
            int anchor_num = nums[i];
            for (size_t j=i+1; j < nums.size(); j++){
                if ((anchor_num + nums[j]) == target){
                    indexes.push_back(i);
                    indexes.push_back(j);
                    return indexes;
                }
            }
        }
        return indexes;
    }
};

int main() {
    vector<int> nums {2,7,11,15};
    int target = 9;
    Solution sol = Solution();
    vector<int> indexes = sol.twoSum(nums, target);
    cout << "indexes: " << indexes[0] << " " << indexes[1] << endl;
}
