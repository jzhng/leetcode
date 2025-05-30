/**
 * @param {number[][]} triangle
 * @return {number}
 */
var minimumTotal = function(triangle) {
  const n = triangle.length;
  const minLevel = [ [triangle[0][0]] ];
  for (let i = 1; i < n; i++) {
    minLevel.push(new Array(i+1).fill(null));
  }

  for (let i = 1; i < n; i++) {
    for (let j = 0; j <=i; j++) {
      minLevel[i][j] = triangle[i][j];
      if (j === 0) {
        minLevel[i][j] += minLevel[i-1][j];
      } else if (j === i) {
        minLevel[i][j] += minLevel[i-1][j-1];
      } else {
        minLevel[i][j] += Math.min(minLevel[i-1][j-1], minLevel[i-1][j]);
      }
    }
  }

  let min = Number.MAX_VALUE;
  for (let i = 0; i < n; i++) {
    min = Math.min(min, minLevel[n-1][i]);
  }
  return min;
};

const triangle = [
    [2],
   [3,4],
  [6,5,7],
 [4,1,8,3]
];

console.info(minimumTotal(triangle));
