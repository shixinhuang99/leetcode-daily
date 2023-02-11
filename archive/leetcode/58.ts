function lengthOfLastWord(s: string): number {
  let count = 1
  let start = false
  for (let i = s.length - 1; i >= 0; i--) {
    if (s[i] !== ' ' && !start) {
      start = true
    } else if (s[i] !== ' ' && start) {
      count++
    } else if (s[i] === ' ' && start) {
      break
    }
  }
  return count
}
