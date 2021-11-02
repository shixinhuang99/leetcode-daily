function romanToInt(s: string): number {
  const map = {
    I: 1,
    V: 5,
    X: 10,
    L: 50,
    C: 100,
    D: 500,
    M: 1000,
    IV: 4,
    IX: 9,
    XL: 40,
    XC: 90,
    CD: 400,
    CM: 900,
  }
  let res = 0
  s = s.replace(/IV|IX|XL|XC|CD|CM/g, (match) => {
    res += map[match]
    return ''
  })
  for (const ch of s) {
    res += map[ch]
  }
  return res
}

function romanToInt2(s: string): number {
  const map = {
    I: 1,
    V: 5,
    X: 10,
    L: 50,
    C: 100,
    D: 500,
    M: 1000,
  }
  let res = 0
  for (let i = 0, l = s.length; i < l; i++) {
    const cur = map[s[i]]
    if (i === l - 1) {
      res += cur
      break
    }
    const next = map[s[i + 1]]
    if (next > cur) {
      res -= cur
    } else {
      res += cur
    }
  }
  return res
}
