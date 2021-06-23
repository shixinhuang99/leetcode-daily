/**
 * @param {number} n - a positive integer
 * @return {number}
 */
var hammingWeight = function (n) {
  const str = n.toString(2)
  let ans = 0
  for (let ch of str) {
    if (ch === '1') {
      ans++
    }
  }
  return ans
}
