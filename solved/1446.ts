function maxPower(s: string): number {
  if (s.length === 1) {
    return 1
  }
  let max = 1
  let count = 1
  for (let i = 0; i < s.length; i++) {
    if (s[i] === s[i + 1]) {
      count += 1
    } else {
      count > max && (max = count)
      count = 1
    }
  }
  return max
}
