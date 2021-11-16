function reverseVowels(s: string): string {
  const map = ['a', 'e', 'i', 'o', 'u']
  const arr: string[] = []
  for (let i = s.length - 1; i >= 0; i--) {
    if (map.indexOf(s[i].toLowerCase()) !== -1) {
      arr.push(s[i])
    }
  }
  const res: string[] = []
  let index = 0
  for (let i = 0, l = s.length; i < l; i++) {
    if (map.indexOf(s[i].toLowerCase()) !== -1) {
      const ch = arr[index++]
      if (ch) {
        res.push(ch)
      }
    } else {
      res.push(s[i])
    }
  }
  return res.join('')
};

function reverseVowels2(s: string): string {
  const map = 'aeiouAEIOU'
  const arr = Array.from(s)
  for (let i = 0, j = arr.length - 1; i < j; ) {
    while (map.indexOf(arr[i]) === -1 && i < j) {
      i++
    }
    while (map.indexOf(arr[j]) === -1 && j > 0) {
      j--
    }
    if (i < j) {
      ;[arr[i], arr[j]] = [arr[j], arr[i]]
      i++
      j--
    }
  }
  return arr.join('')
};
