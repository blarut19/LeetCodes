/**
 * @param {number} n
 * @param {number[][]} edges
 * @return {number[][]}
 */
var getAncestors = function(n, edges){
    let ans = new Array(n);
    let res = new Array(n);
    for(let i = 0; i < n; i++) {
        ans[i] = new Array();
        res[i] = new Array();
    }
    for(edge of edges) {ans[edge[0]].push(edge[1]);}

    for(let i = 0; i < n; i++)
        DFS(ans, i, i, res, new Array(n).fill(false));

    for(let i = 0; i < n; i++)
        res[i].sort(function(a, b){return a-b});

    return res;

    function DFS(graph, parent, curr, res, visited){
        visited[curr] = true;
        for(dest of graph[curr]){
            if(!visited[dest]){
                res[dest].push(parent);
                DFS(graph, parent, dest, res, visited);
            }
        }
    }
};