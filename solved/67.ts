function addBinary(a: string, b: string): string {
  const aNum = BigInt('0b' + a)
  const bNum = BigInt('0b' + b)
  return (aNum + bNum).toString(2)
}

function addBinary2(a: string, b: string): string {
  if (a.length < b.length) {
    a = '0'.repeat(b.length - a.length) + a
  } else if (b.length < a.length) {
    b = '0'.repeat(a.length - b.length) + b
  }
  let ans: string[] = []
  for (let i = a.length - 1, j = 0; i >= 0; i--, j++) {
    const aNum = a[i] === '1' ? 1 : 0
    const bNum = b[i] === '1' ? 1 : 0
    const resNum = ans[j] === '1' ? 1 : 0
    const res = aNum + bNum + resNum
    if (res === 2) {
      ans[j] = '0'
      ans[j + 1] = '1'
    } else if (res === 3) {
      ans[j] = '1'
      ans[j + 1] = '1'
    } else if (res === 1) {
      ans[j] = '1'
    } else {
      ans[j] = '0'
    }
  }
  return ans.reverse().join('')
}
