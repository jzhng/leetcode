// 847. Shortest Path Visiting All Nodes
// https://leetcode.com/problems/shortest-path-visiting-all-nodes/
// WA !!!

/**
 * @param {number[][]} graph
 * @return {number}
 */
var shortestPathLength = function(graph) {
  const dp = [];
  const q = [];
  for (let i = graph.length - 1; i >= 0; i--) {
    dp[i] = [];
    dp[i][1 << i] = 0;
    q.push([i, 1 << i]);
  }

  for (let i = 0; i < graph.length; i++) {
    // console.info(dp[i]);
    // console.info(q);
  }

  while (q.length) {
    const d = q.shift();
    console.info(d);
    for (let i of graph[d[0]]) {
      let state = d[1] | 1 << i;
      console.info(state);
      if (!dp[i][state] || dp[i][state] > dp[d[0]][d[1]] + 1) {
        dp[i][state] = dp[d[0]][d[1]] + 1;
        q.push([i, state]);
      }
    }
  }

  let mn = 1000;
  // console.info(101200);
  for (let i = 0; i < graph.length; i++) {
    console.info(dp[i][1 << graph.length -1]);
    mn = Math.min(mn, dp[i][1 << graph.length -1]);
  }
  return mn;
};

const graph1 = [[1, 2, 3], [0], [0], [0]];
const graph2 = [[1], [0, 2, 4], [1, 3, 4], [2], [1, 2]];
console.info(shortestPathLength(graph1));
// console.info(shortestPathLength(graph2));
