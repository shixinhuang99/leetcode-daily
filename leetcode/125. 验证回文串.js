/**
 * @param {string} s
 * @return {boolean}
 */
var isPalindrome = function(s) {
    let copy = s.replace(/\W|_/g, "").toLowerCase();
    let l = 0;
    let r = copy.length - 1;
    while (l < r) {
        if (copy[l++] !== copy[r--]) return false;
    }
    return true;
};