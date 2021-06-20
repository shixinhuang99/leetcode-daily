/*
 * @Author       : ApassEr
 * @Date         : 2020-06-04 12:35:15
 * @LastEditTime : 2020-06-04 12:36:22
 * @Description  : 300. 最长上升子序列
 * @Algorithm    : dp
 */
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> dp(nums.size() + 1, 1e6);
        int max = dp[0];
        for (int i = 0; i < (int)nums.size(); ++i) {
            *lower_bound(dp.begin(), dp.end(), nums[i]) = nums[i];
        }
        int len = 0;
        while (dp[len] != max) {
            ++len;
        }
        return len;
    }
};