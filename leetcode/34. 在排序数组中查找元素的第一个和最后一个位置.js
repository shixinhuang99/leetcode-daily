/**
 * @param {number[]} nums
 * @param {number} target
 * @return {number[]}
 */
var searchRange = function(nums, target) {
    let mid, ansL, ansR;
    var searchR = function(l, r, target) {
        while (l <= r) {
            mid = (l + r) >> 1;
            if (nums[mid] <= target) {
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }
        return r;
    }
    ansR = searchR(0, nums.length - 1, target);
    if (ansR < 0 || nums[ansR] !== target) return [-1, -1];
    ansL = searchR(0, ansR - 1, target - 1);
    return [ansL + 1, ansR];
};

var searchRange = function(nums, target) {
    let l = 0;
    let r = nums.length - 1;
    let mid;
    while (l <= r) {
        mid = (l + r) >> 1;
        if (nums[mid] < target) {
            l = mid + 1;
        } else if (nums[mid] > target) {
            r = mid - 1;
        } else {
            break;
        }
    }
    if (l > r) return [-1, -1];
    let i = mid;
    let j = mid;
    while (nums[i] === nums[i - 1]) --i;
    while (nums[j] === nums[j + 1]) ++j;
    return [i, j];
};