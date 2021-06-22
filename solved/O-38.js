/**
 * @param {string} s
 * @return {string[]}
 */
var permutation = function (s) {
  if (s.length === 1) {
    return [s]
  }
  const arr = s.split('')
  const nextPermutation = (arr) => {
    const len = arr.length
    let i = len - 1
    for (;;) {
      const ii = i--
      if (arr[i] < arr[ii]) {
        let j = len - 1
        while (arr[j] <= arr[i]) {
          j--
        }
        ;[arr[j], arr[i]] = [arr[i], arr[j]]
        const rest = arr.slice(ii).reverse()
        arr.splice(ii, len - ii, ...rest)
        return arr.join('')
      }
      if (i === 0) {
        arr.reverse()
        return arr.join('')
      }
    }
  }
  const results = []
  let result = ''
  do {
    result = nextPermutation(arr)
    results.push(result)
  } while (result !== s)
  return results
}
