/**
 * @param {number[]} nums
 * @return {number}
 */
var lengthOfLIS = function(nums) {
    let len = nums.length;
    let dp = new Array(len + 1).fill(1e6);
    let max = dp[0];
    for (let i = 0; i < len; ++i) {
        let first = 0;
        let len_dp = len + 1;
        let half, mid;
        while (len_dp > 0) {
            half = len_dp >> 1;
            mid = first + half;
            if (dp[mid] < nums[i]) {
                first = mid + 1;
                len_dp = len_dp - half - 1;
            } else {
                len_dp = half;
            }
        }
        dp[first] = nums[i];
    }
    let ret = 0;
    while (dp[ret] !== max) {
        ++ret;
    }
    return ret;
};