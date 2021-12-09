function plusOne(digits: number[]): number[] {
  const _digits = digits.slice()
  for (let i = _digits.length - 1; i >= 0; i--) {
    _digits[i] += 1
    if (_digits[i] > 9) {
      _digits[i] = 0
    } else {
      break
    }
  }
  if (_digits[0] === 0) {
    _digits.unshift(1)
  }
  return _digits
}
