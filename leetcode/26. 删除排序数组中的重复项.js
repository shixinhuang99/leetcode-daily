/**
 * @param {number[]} nums
 * @return {number}
 */
var removeDuplicates = function(nums) {
    let len = nums.length;
    if (!len) return 0;
    let cnt = 0;
    for (let i = 1; i < len; ++i) {
        if (nums[i] !== nums[i - 1]) {
            ++cnt;
            nums[cnt] = nums[i];
        }
    }
    return cnt + 1;
};