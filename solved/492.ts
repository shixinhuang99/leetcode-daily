// start
function constructRectangle(area: number): number[] {
  let w = Math.floor(Math.sqrt(area));

  while (area % w !== 0) {
    w -= 1;
  }

  return [area / w, w];
}
// end

if (import.meta.vitest) {
  const { test, expect } = import.meta.vitest;

  const cases: [number, number[]][] = [
    [4, [2, 2]],
    [37, [37, 1]],
    [122122, [427, 286]],
  ];

  test.each(cases)('test %#', (area: number, ans: number[]) => {
    expect(constructRectangle(area)).toEqual(ans);
  });
}
