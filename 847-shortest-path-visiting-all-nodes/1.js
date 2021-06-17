// 847. Shortest Path Visiting All Nodes
// https://leetcode.com/problems/shortest-path-visiting-all-nodes/
// WA !!!

/**
 * @param {number[][]} graph
 * @return {number}
 */
var shortestPathLength = function(graph) {
  const visited = [];

  function dfs(start, depth) {
    let ret = depth;
    visited[start] = true;
    for (let i of graph[start]) {
      if (!visited[i]) {
        ret = Math.max(ret, dfs(i, depth + 1));
        if (ret === graph.length - 1) break;
      }
    }
    visited[start] = false;
    return ret;
  }

  let longestSinglePath = 0;
  for (let i = 0; i < graph.length; i++) {
    longestSinglePath = Math.max(longestSinglePath, dfs(i, 0));
  }
  return 2 * (graph.length - 1) - longestSinglePath;
};

const graph1 = [[1, 2, 3], [0], [0], [0]];
const graph2 = [[1], [0, 2, 4], [1, 3, 4], [2], [1, 2]];
console.info(shortestPathLength(graph1));
console.info(shortestPathLength(graph2));
