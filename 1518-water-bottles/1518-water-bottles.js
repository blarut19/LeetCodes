/**
 * @param {number} numBottles
 * @param {number} numExchange
 * @return {number}
 */
var numWaterBottles = function(numBottles, numExchange) {
    if(numBottles < numExchange)
        return numBottles;
    let undrunk = numBottles%numExchange;
    return Math.floor(numBottles - undrunk) + numWaterBottles(Math.floor(numBottles/numExchange) + undrunk, numExchange);
};
