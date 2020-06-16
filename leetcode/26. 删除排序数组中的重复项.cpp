/*
 * @Author       : ApassEr
 * @Date         : 2020-06-16 14:53:53
 * @LastEditTime : 2020-06-16 14:56:09
 * @Description  : 26. 删除排序数组中的重复项
 * @Algorithm    : 水题
 */
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if (nums.empty()) return 0;
        int cnt = 0;
        for (int i = 1; i < (int)nums.size(); ++i) {
            if (nums[i] != nums[i - 1]) {
                ++cnt;
                nums[cnt] = nums[i];
            }
        }
        return cnt + 1;
    }
};