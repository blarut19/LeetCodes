/**
 * @param {number} n
 * @param {number} time
 * @return {number}
 */
var passThePillow = function(n, time) {
    let k = Math.floor(time/(n-1)) % 2;
    let r = time % (n-1);

    if(k == 0)
        return r + 1;
    else
        return n - r;
};