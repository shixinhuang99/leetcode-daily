/**
 * 贪心
 */
function distributeCandies(candyType: number[]): number {
  const foo = new Set(candyType).size
  const bar = candyType.length / 2
  if (foo > bar) {
    return bar
  }
  return foo
}
