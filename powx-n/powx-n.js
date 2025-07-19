/**
 * @param {number} x
 * @param {number} n
 * @return {number}
 */
var myPow = function(x, n) {
    if (n === 0) return 1;
    
    // Handle negative powers
    if (n < 0) return 1 / myPow(x, -n);

    // Optimize by dividing the power
    if (n % 2 === 0) {
        const half = myPow(x, n / 2);
        return half * half;
    } else {
        return x * myPow(x, n - 1);
    }
};