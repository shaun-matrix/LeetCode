#include "common.h"

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        // special cases
        if (nums.size() == 1){
            return nums[0];
        }
        // initialize vaules
        int tmpSum = nums[0];
        int finalSum = nums[0];
        vector<int> tmpNums;
        tmpNums.push_back(nums[0]);

        for (int i = 1; i<nums.size(); i++){
            if (tmpSum < 0){
                tmpNums.clear();
                tmpNums.push_back(nums[i]);
                tmpSum = nums[i];
            }else{
                tmpNums.push_back(nums[i]);
                tmpSum += nums[i];
            }
            if (tmpSum > finalSum){
                finalSum = tmpSum;
            }
        }

        return finalSum;
    }
};

// dynamic programming
class SolutionDP {
public:
    int maxSubArray(vector<int>& nums) {
        // special cases
        //if (nums.size() == 1){
        //    return nums[0];
        //}

        int preSum = nums[0];
        int maxSum = nums[0];
        int curSum;
        for (size_t i = 1; i < nums.size(); i++){
            curSum = preSum + nums[i] > nums[i] ? preSum + nums[i] : nums[i];
            maxSum = maxSum > curSum ? maxSum : curSum;
            preSum = curSum;
        }
        return maxSum;
    }
};

// divide conquer
class SolutionDC {
public:
    struct status{
        int lSum; int rSum; int mSum; int iSum;
    };

    status get_status(vector<int>& nums, int l, int r){
        status s;
        if (l == r){
            s.lSum = nums[l]; s.rSum = nums[l]; s.mSum = nums[l]; s.iSum = nums[l];
            return s;
        }
        int m = (l + r) / 2;
        status ls = get_status(nums, l, m);
        status rs = get_status(nums, m+1, r);
        // calc lSum
        s.lSum = (ls.lSum > ls.iSum + rs.lSum) ? ls.lSum : ls.iSum + rs.lSum;
        // calc rSum
        s.rSum = (rs.rSum > rs.iSum + ls.rSum) ? rs.rSum : rs.iSum + ls.rSum;
        // calc mSum
        s.mSum = (ls.mSum > rs.mSum) ? ls.mSum : rs.mSum;
        s.mSum = (s.mSum > ls.rSum + rs.lSum) ? s.mSum : ls.rSum + rs.lSum;
        // calc iSum
        s.iSum = ls.iSum + rs.iSum;
        return s;
    }

    int maxSubArray(vector<int>& nums) {
        status s = get_status(nums, 0, nums.size()-1);
        return s.mSum;
    }
};

int main() {
    //vector<int> nums {-2,1,-3,4,-1,2,1,-5,4};
    //vector<int> nums {-1,-3,-5};
    //vector<int> nums {-1,-3,1};
    vector<int> nums {1};
    //vector<int> nums {5,4,-1,7,8};
    SolutionDC sol = SolutionDC();
    int finalSum = sol.maxSubArray(nums);
    cout << "sub array max: " << finalSum << endl;
}
