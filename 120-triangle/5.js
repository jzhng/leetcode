/**
 * @param {number[][]} triangle
 * @return {number}
 */
var minimumTotal = function(triangle) {
  const n = triangle.length;
  const min = [...triangle[n-1]];
  for (let level = n - 2; level >=0; level--) {
    for (let i = 0; i <= level; i++) {
      min[i] = Math.min(min[i], min[i+1]) + triangle[level][i];
    }
  }
  return min[0];
};

const triangle = [
    [2],
   [3,4],
  [6,5,7],
 [4,1,8,3]
];

console.info(minimumTotal(triangle));
