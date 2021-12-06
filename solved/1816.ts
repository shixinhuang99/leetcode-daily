function truncateSentence(s: string, k: number): string {
  const arr = s.split(' ')
  arr.length = k
  return arr.join(' ')
}

function truncateSentence2(s: string, k: number): string {
  let i = 0
  for (let j = 0, l = s.length; i < l; i++) {
    if (s[i] === ' ') {
      j++
    }
    if (j === k) {
      break
    }
  }
  return s.slice(0, i)
}
