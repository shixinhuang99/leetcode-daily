function maxCount(m: number, n: number, ops: number[][]): number {
  let xMin = m
  let yMin = n
  for (const op of ops) {
    const x = op[0]
    const y = op[1]
    if (x < xMin) {
      xMin = x
    }
    if (y < yMin) {
      yMin = y
    }
  }
  return xMin * yMin
};
