/*
 * @Author       : ApassEr
 * @Date         : 2020-06-15 16:58:05
 * @LastEditTime : 2020-06-15 17:08:58
 * @Description  : 31. 下一个排列
 * @Algorithm    : 参考STL:next_permutation源码
 */
class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        if (nums.size() <= 1) return;
        auto before = nums.end() - 1;
        for (;;) {
            auto after = before--;
            if (*before < *after) {
                auto upper = nums.end();
                while (!(*before < *--upper));
                iter_swap(before, upper);
                reverse(after, nums.end());
                return;
            }
            if (before == nums.begin()) {
                reverse(nums.begin(), nums.end());
                return;
            }
        }
    }
};