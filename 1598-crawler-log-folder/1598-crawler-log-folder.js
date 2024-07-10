/**
 * @param {string[]} logs
 * @return {number}
 */
var minOperations = function(logs) {
    let stepN = 0;
    for(let log of logs){
        if(log == "../"){
            stepN--;
            if(stepN < 0){
                stepN = 0;
            }
        }
        else if(log != "./"){
            stepN++;
        }
    }
    return stepN;
};