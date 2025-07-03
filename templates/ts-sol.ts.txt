// start

// end

if (import.meta.vitest) {
  const { test, expect } = import.meta.vitest;

  const cases = [];

  test.each(cases)('test %#', () => {});
}
