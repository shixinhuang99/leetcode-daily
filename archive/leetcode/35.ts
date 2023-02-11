function searchInsert(nums: number[], target: number): number {
  let l = 0
  let r = nums.length - 1
  while (l <= r) {
    let mid = ((r - l) >> 1) + l
    if (target <= nums[mid]) {
      r = mid - 1
    } else {
      l = mid + 1
    }
  }
  return l
}
