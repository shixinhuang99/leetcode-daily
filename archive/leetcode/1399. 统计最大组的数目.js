/**
 * @param {number} n
 * @return {number}
 */
var countLargestGroup = function(n) {
  const group = new Map()
  const getSum = (num) => {
    let res = 0
    while (num > 1) {
      res += num % 10
      num = Math.floor(num / 10)
    }
    return res + num
    // return [...String(num)].reduce((a, b) => Number(a) + Number(b))
  }
  let max = 1
  for (let i = 1; i <= n; i++) {
    const key = getSum(i)
    if (group.has(key)) {
      const newVal = group.get(key) + 1
      if (newVal > max) {
        max = newVal
      }
      group.set(key, newVal)
    } else {
      group.set(key, 1)
    }
  }
  let res = 0
  for (let val of group.values()) {
    if (val === max) {
      res++
    }
  }
  return res
};
