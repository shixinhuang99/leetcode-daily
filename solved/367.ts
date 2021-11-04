/**
 * 牛顿迭代法
 */
function isPerfectSquare(num: number): boolean {
  let x = 1
  let flag = false
  while (true) {
    let nx = (x + num / x) >> 1
    if (x === nx || (nx > x && flag)) {
      break
    }
    flag = nx < x
    x = nx
  }
  return x * x === num
}

/**
 * 二分法
 */
function isPerfectSquare2(num: number): boolean {
  let l = 0
  let r = num
  while (l <= r) {
    const mid = Math.floor((r - l) >> 1) + l
    const s = mid * mid
    if (s > num) {
      r = mid - 1
    } else if (s < num) {
      l = mid + 1
    } else {
      return true
    }
  }
  return false
}
