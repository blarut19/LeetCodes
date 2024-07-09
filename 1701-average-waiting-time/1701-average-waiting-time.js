/**
 * @param {number[][]} customers
 * @return {number}
 */
var averageWaitingTime = function(customers) {
    let currTime = 1;
    let serveTime = 0;
    let i = 0;
    for(let customer of customers){
        if(customer[0] > currTime)
            currTime = customer[0];
        else
            serveTime += currTime - customer[0];
        serveTime += customer[1];
        currTime += customer[1];
        i++;
    }
    return (serveTime) / i;
};