/**
 * @param {number} n
 * @param {number} k
 * @return {number[][]}
 */
var combine = function(n, k) {
    const result = [];

    const backtrack = (start, combo) => {
        if (combo.length === k) {
            result.push([...combo]);
            return;
        }

        for (let i = start; i <= n; i++) {
            combo.push(i);
            backtrack(i + 1, combo);
            combo.pop(); // backtrack
        }
    };

    backtrack(1, []);
    return result;
};