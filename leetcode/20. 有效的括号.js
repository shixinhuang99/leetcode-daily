/**
 * @param {string} s
 * @return {boolean}
 */
var isValid = function(s) {
    let len = s.length;
    if (!len) return true;
    if (len % 2) return false;
    let stack = [];
    let map = {
        ")": "(",
        "]": "[",
        "}": "{",
    };
    for (let ch of s) {
        if (ch === ")" || ch === "]" || ch === "}") {
            if (stack.length && stack.pop() !== map[ch]) {
                return false;
            }
        } else {
            stack.push(ch);
        }
    }
    return !stack.length;
};