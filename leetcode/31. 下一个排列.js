/**
 * @param {number[]} nums
 * @return {void} Do not return anything, modify nums in-place instead.
 */
var nextPermutation = function(nums) {
    let len = nums.length;
    if (len <= 1) return;
    let before = len - 1;
    for (;;) {
        let after = before--;
        if (nums[before] < nums[after]) {
            let upper = len;
            while (!(nums[before] < nums[--upper]));
            [nums[before], nums[upper]] = [nums[upper], nums[before]];
            let part = nums.slice(after);
            part.reverse();
            nums.splice(after, len - after);
            for (let i of part) {
                nums.push(i);
            }
            return;
        }
        if (!before) {
            nums.reverse();
            return;
        }
    }
};