/**
 * @param {number} n
 * @return {number[][]}
 */
var generateMatrix = function(n) {
    let ret = [];
    for (let i = 0; i < n; ++i) {
        ret[i] = [];
    }
    let init = 1;
    let top = 0;
    let bottom = n - 1;
    let left = 0;
    let right = n - 1;
    while (init <= n * n) {
        for (let i = left; i <= right; ++i) {
            ret[top][i] = init++;
        }
        ++top;
        for (let i = top; i <= bottom; ++i) {
            ret[i][right] = init++;
        }
        --right;
        for (let i = right; i >= left; --i) {
            ret[bottom][i] = init++;
        }
        --bottom;
        for (let i = bottom; i >= top; --i) {
            ret[i][left] = init++;
        }
        ++left;
    }
    return ret;
};