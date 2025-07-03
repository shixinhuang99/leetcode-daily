// start
function addDigits(num: number): number {
  while (num > 9) {
    let sum = 0;
    while (num > 0) {
      sum += num % 10;
      num = Math.floor(num / 10);
    }
    num = sum;
  }

  return num;
}
// end

if (import.meta.vitest) {
  const { test, expect } = import.meta.vitest;

  const cases = [
    [38, 2],
    [0, 0],
    [1, 1],
    [10, 1],
    [2 ** 31 - 1, 1],
  ];

  test.each(cases)('test %#', (num: number, ans: number) => {
    expect(addDigits(num)).toBe(ans);
  });
}
