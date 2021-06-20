/**
 * @param {number} x
 * @return {boolean}
 */
var isPalindrome = function(x) {
    if (x < 0) return false;
    else if (x && !(x % 10)) return false;
    let copy = x;
    let ret = 0;
    while (copy > 0) {
        ret = ret * 10 + copy % 10;
        copy = (copy / 10) >> 0;
    }
    return ret === x;
};