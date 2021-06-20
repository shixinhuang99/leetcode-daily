/**
 * @param {number} x
 * @return {number}
 */
var reverse = function(x) {
    let ans = 0;
    let isNegative = x < 0 ? true : false;
    if (isNegative) x = -x;
    while (x > 0) {
        ans = ans * 10 + x % 10;
        x = (x / 10) >> 0;
    }
    if (ans > 0x7fffffff) {
        return 0;
    }
    return isNegative ? -ans : ans;
};