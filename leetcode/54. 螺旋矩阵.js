/**
 * @param {number[][]} matrix
 * @return {number[]}
 */
var spiralOrder = function(matrix) {
    if (!matrix.length) return [];
    let init = matrix.length * matrix[0].length;
    let ret = [];
    let top = 0;
    let bottom = matrix.length - 1;
    let left = 0;
    let right = matrix[0].length - 1;
    while (init > 0) {
        for (let i = left; init > 0 && i <= right; ++i, --init) {
            ret.push(matrix[top][i]);
        }
        ++top;
        for (let i = top; init > 0 && i <= bottom; ++i, --init) {
            ret.push(matrix[i][right]);
        }
        --right;
        for (let i = right; init > 0 && i >= left; --i, --init) {
            ret.push(matrix[bottom][i]);
        }
        --bottom;
        for (let i = bottom; init > 0 && i >= top; --i, --init) {
            ret.push(matrix[i][left]);
        }
        ++left;
    }
    return ret;
};