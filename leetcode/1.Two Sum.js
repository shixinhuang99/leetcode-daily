/*
 * @Author       : ApassEr
 * @Date         : 2020-03-31 23:05:27
 * @LastEditTime : 2020-03-31 23:06:32
 * @Description  : Two Sum
 * @Algorithm    : hash
 */
/**
 * @param {number[]} nums
 * @param {number} target
 * @return {number[]}
 */
var twoSum = function(nums, target) {
    var map = new Array();
    for (let i = 0; i != nums.length; ++i) {
        let find = target - nums[i];
        if (map[find] != undefined) {
            return [map[find], i];
        }
        map[nums[i]] = i;
    }
};