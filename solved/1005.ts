function largestSumAfterKNegations(nums: number[], k: number): number {
  const _nums = nums.slice()
  _nums.sort((a, b) => a - b)
  for (let i = 0, l = _nums.length; i < l && k !== 0; i++) {
    if (_nums[i] < 0) {
      _nums[i] = -_nums[i]
      k--
    } else {
      break
    }
  }
  _nums.sort((a, b) => a - b)
  if (k % 2 !== 0) {
    _nums[0] = -_nums[0]
  }
  return _nums.reduce((a, b) => a + b)
}
