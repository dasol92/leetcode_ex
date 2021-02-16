// Problem from https://leetcode.com/problems/find-all-numbers-disappeared-in-an-array/

#include <vector>

using namespace std;

class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        vector<int> res(nums.size(), 0);
        for (int i = 0; i < nums.size(); i++) {
            int index = nums[i] - 1;
            res[index] = -1;
        }
        vector<int> out;
        for (int i = 0; i < res.size(); i++) {
            if (res[i] >= 0) {
                out.push_back(i+1);
            }
        }
        return out;
    }
};