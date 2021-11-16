function removeElement(nums: number[], val: number): number {
  for (let i = 0; i < nums.length; ) {
    if (nums[i] === val) {
      nums.splice(i, 1)
    } else {
      i += 1
    }
  }
  return nums.length
};

function removeElement2(nums: number[], val: number): number {
  let res = 0
  for (let i = 0, l = nums.length; i < l; i++) {
    if (nums[i] !== val) {
      nums[res++] = nums[i]
    }
  }
  return res
};
