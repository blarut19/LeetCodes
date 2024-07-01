/**
 * @param {number[]} arr
 * @return {boolean}
 */
var threeConsecutiveOdds = function(arr) {
    let consecutiveOdds = 0;
    for(let num of arr){
        if(num%2==1)
            consecutiveOdds++;
        else
            consecutiveOdds = 0;
        if(consecutiveOdds >= 3)
            return true
    }
    return false
    
};